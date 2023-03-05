#include "FrmSourceEdit.h"

#include <QVBoxLayout>
#include <QTextStream>
#include <QSettings>
#include <QList>
#include <QUrl>
#include "Qsci/qscilexeras.h"
#include "Qsci/qscilexercustom.h"
#include <QDebug>
#include <QTextCodec>

//--- InstandLuaX Framework -----------------------------------------------------------------------
#include "Settings.h"
#include "Locker.h"
#include "Qsci/qscilexerpascal.h"
//-------------------------------------------------------------------------------------------------
FrmSourceEdit::FrmSourceEdit(FrmFileExplorer *pParent, IFile::ptr_type pFile)
    :QWidget(pParent)
    ,m_pSrcEdit(NULL)
    ,m_pFile(pFile)
    ,m_pFileExplorer(pParent)
    ,m_nMarkerBreakpoint(0)
    ,m_nMarkerCIP(0)
    ,m_nMarkerLine(0)
    ,m_nMarkerError(0)
    ,m_nMarkerPotentialBreakpoint(0)
    ,m_vMarkedLines()
    ,m_nErrorLine(-1)
    ,m_nNumberIndicator(0)
{
    try
    {
        m_pSrcEdit = new QsciScintilla(this);

        connect(m_pSrcEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));

        connect(m_pSrcEdit, SIGNAL(modificationChanged(bool)), this, SLOT(fileModified(bool)));

        connect(m_pSrcEdit, SIGNAL(linesChanged()), this, SLOT(linesChanged()));

        connect(m_pSrcEdit, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(cursorMoved(int,int)));

        connect(m_pSrcEdit, SIGNAL(indicatorClicked(int, int, Qt::KeyboardModifiers)), this, SLOT(indicatorClicked(int, int,Qt::KeyboardModifiers)));

        connect(m_pSrcEdit, SIGNAL(marginClicked(int, int, Qt::KeyboardModifiers)), this, SLOT(marginClicked(int, int,Qt::KeyboardModifiers)));

/*
        //! This signal is emitted whenever text is selected or de-selected.
        //! \a yes is true if text has been selected and false if text has been
        //! deselected.  If \a yes is true then copy() can be used to copy the
        //! selection to the clipboard.  If \a yes is false then copy() does
        //! nothing.
        //!
        //! \sa copy(), selectionChanged()
        void copyAvailable(bool yes);

        //! This signal is emitted whenever the user clicks on an indicator.  \a
        //! line is the number of the line where the user clicked.  \a index is the
        //! character index within the line.  \a state is the state of the modifier
        //! keys (Qt::ShiftModifier, Qt::ControlModifier, Qt::AltModifer and
        //! Qt::MetaModifier) when the user clicked.
        //!
        //! \sa indicatorReleased()
        void indicatorClicked(int line, int index, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the user releases the mouse on an
        //! indicator.  \a line is the number of the line where the user clicked.
        //! \a index is the character index within the line.  \a state is the state
        //! of the modifier keys (Qt::ShiftModifier, Qt::ControlModifier,
        //! Qt::AltModifer and Qt::MetaModifier) when the user released the mouse.
        //!
        //! \sa indicatorClicked()
        void indicatorReleased(int line, int index, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the number of lines of text changes.
        void linesChanged();

        //! This signal is emitted whenever the user clicks on a sensitive margin.
        //! \a margin is the margin.  \a line is the number of the line where the
        //! user clicked.  \a state is the state of the modifier keys
        //! (Qt::ShiftModifier, Qt::ControlModifier, Qt::AltModifer and
        //! Qt::MetaModifier) when the user clicked.
        //!
        //! \sa marginSensitivity(), setMarginSensitivity()
        void marginClicked(int margin, int line, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the user attempts to modify read-only
        //! text.
        //!
        //! \sa isReadOnly(), setReadOnly()
        void modificationAttempted();

        //! This signal is emitted whenever the modification state of the text
        //! changes.  \a m is true if the text has been modified.
        //!
        //! \sa isModified(), setModified()
        void modificationChanged(bool m);

        //! This signal is emitted whenever the selection changes.
        //!
        //! \sa copyAvailable()
        void selectionChanged();

        //! This signal is emitted whenever the text in the text edit changes.
        void textChanged();

        //! This signal is emitted when an item in a user defined list is activated
        //! (selected).  \a id is the list identifier.  \a string is the text of
        //! the item.
        //!
        //! \sa showUserList()
        void userListActivated(int id, const QString &string);
*/


        // Lexer konfigurieren
        //new QsciLexerPascal;
        QsciLexerAs*pLexer = new QsciLexerAs;
        pLexer->setFont(QFont("Courier New", 10));
        
        m_pSrcEdit->setUtf8(true);
        m_pSrcEdit->setLexer(pLexer);
        m_pSrcEdit->setEolMode(QsciScintilla::EolUnix);

        // Margins
        m_pSrcEdit->setMarginWidth(0, 40);
        m_pSrcEdit->setMarginType(0, QsciScintilla::NumberMargin);
        m_pSrcEdit->setMarginLineNumbers(0, true);

        m_pSrcEdit->setMarginWidth(1, 40);
        m_pSrcEdit->setMarginType(1, QsciScintilla::SymbolMargin /*DefaultBackgroundColor*/);
        m_pSrcEdit->setMarginSensitivity(1, true);  // marginClick Signale freischalten

        // Auto complete
        m_pSrcEdit->setAutoCompletionThreshold(2);
        m_pSrcEdit->setAutoCompletionCaseSensitivity(true);
        m_pSrcEdit->setAutoCompletionSource(QsciScintilla::AcsAll);

        // misc
        m_pSrcEdit->setBraceMatching(QsciScintilla::StrictBraceMatch);
        m_pSrcEdit->setAcceptDrops(true);

        // Markieren für überlange Zeilen
        // ab 80 Spalten ist eine Zeile als zu lang zu markieren. Die GUI
        // ist darauf ausgelegt Debugpanel einzublenden, daher sollte die
        // Ideale Zeilenbreite angezeigt werden. Wenn der Nutzer
        // drüberschreibt ist er selber schuld
        m_pSrcEdit->setEdgeColumn(80);
        m_pSrcEdit->setEdgeMode(QsciScintilla::EdgeLine);

        // Marker definieren (Haltepunkte und Instruktionpointer)
        m_nMarkerPotentialBreakpoint = m_pSrcEdit->markerDefine(QsciScintilla::FullRectangle);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(200, 200, 210), m_nMarkerPotentialBreakpoint);

        m_nMarkerBreakpoint = m_pSrcEdit->markerDefine(QsciScintilla::Circle);
        m_pSrcEdit->setMarkerForegroundColor(QColor("black"), m_nMarkerBreakpoint);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(150, 50, 50),   m_nMarkerBreakpoint);

        m_nMarkerCIP = m_pSrcEdit->markerDefine(QsciScintilla::RightArrow);
        m_pSrcEdit->setMarkerForegroundColor(QColor("black"), m_nMarkerCIP);
        m_pSrcEdit->setMarkerBackgroundColor(QColor("green"), m_nMarkerCIP);

        m_nMarkerLine = m_pSrcEdit->markerDefine(QsciScintilla::Background);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(180, 255, 180), m_nMarkerLine);
        m_pSrcEdit->setCaretLineBackgroundColor(Qt::lightGray);
        m_pSrcEdit->setFoldMarginColors(Qt::gray, Qt::lightGray);

//        m_nMarkerError = m_pSrcEdit->markerDefine(QsciScintilla::Background);
        m_nMarkerError = m_pSrcEdit->markerDefine(QsciScintilla::Underline);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(255, 180, 180), m_nMarkerError);
        m_pSrcEdit->setFolding(QsciScintilla::BoxedTreeFoldStyle,2); 
        const Settings& settings = Settings::Instance();
        QFont font("Courier New", settings.getFontSize());
        QFontMetrics fontmetrics = QFontMetrics(font);
        m_pSrcEdit->setMarginWidth(0, fontmetrics.width("00000"));
        m_pSrcEdit->setMarginMarkerMask(1, 255);

        // Indikatoren
        m_nNumberIndicator = m_pSrcEdit->indicatorDefine(QsciScintilla::StrikeIndicator /*RoundBoxIndicator*/);

        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->addWidget(m_pSrcEdit);
        vbox->setMargin(0);
        setLayout(vbox);
    }
    catch(...)
    {
        // no problem, editor remains empty. Constructor may not fail!
    }
}

//-------------------------------------------------------------------------------------------------
FrmSourceEdit::~FrmSourceEdit()
{}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::fileModified(bool bStat)
{
    updateFile(true);
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::textChanged()
{
    //updateFile(true);

    // Stellenweise hat fileModified nicht mehr getriggert, Grund unbekannt...
    // textChanged sollte immer triggern
    qDebug() << "textChanged()";
}

//-------------------------------------------------------------------------------------------------
/** \brief Synchronisiert den Inhalt der Scintilla Komponente mit dem zwischengepufferten Inhalt
           in m_pFile.

    Das Modified flag von m_pFile wird gesetzt.
*/
void FrmSourceEdit::updateFile(bool bSetModifiedFlag)
{
    if (m_pFile==NULL)
        return;

    int nLines = m_pSrcEdit->lines();

    Locker lock(m_pFile.data());

    m_pFile->clear();

    for (int i=0; i<nLines; ++i)
    {
        QString sLine = m_pSrcEdit->text(i);
        m_pFile->addLine(sLine);
    }

    if (bSetModifiedFlag)
    {
        m_pFile->setModified(true);
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Update the markers indicating possible breakpoints. */
void FrmSourceEdit::updateBreakpointIndicators()
{
    int nLines = m_pFile->getNumLines();
    for (int i=0; i<nLines; ++i)
    {
        if (lineAcceptsBreakpoints(i))
        {
            m_pSrcEdit->markerAdd(i, m_nMarkerPotentialBreakpoint);
        }
        else
        {
            m_pSrcEdit->markerDelete(i, m_nMarkerPotentialBreakpoint);
        }
    }
}

//-------------------------------------------------------------------------------------------------
bool FrmSourceEdit::lineAcceptsBreakpoints(int nLine)
{
    int nLines = m_pFile->getNumLines();
    if (nLine>nLines)
        return false;

    QString sLine = m_pFile->getLine(nLine).trimmed();

    // Einzeiliger Lua Kommentar
    if (sLine[0]=='-' && sLine[1]=='-')
        return false;

    // leere Zeile
    if (sLine.length()==0)
        return false;

    // Wenn die vorhergehende Zeile mit einem Komma endet kann kein
    // Haltepunkt gesetzt werden.
    if (nLine>1)
    {
        QString sPrevLine = m_pFile->getLine(nLine-1).trimmed();
        if (sPrevLine.length()>0 && sPrevLine[sPrevLine.length()-1]==',')
            return false;
    }

    return true;
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::linesChanged()
{
    if (m_pFile==NULL)
        return;

    qDebug() << "linesChanged()";
    updateBreakpointIndicators();

    m_pFile->updateOutline();
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::marginClicked(int nMargin, int nLine, Qt::KeyboardModifiers eState)
{
    if (nMargin==1)
    {
        m_pSrcEdit->fillIndicatorRange(1, 10, 0, 0, m_nNumberIndicator);

        int nMarkers = m_pSrcEdit->markersAtLine(nLine);

        // Dürfen Haltepunkte gesetzt werden?
        if ((nMarkers & 1<<m_nMarkerPotentialBreakpoint)==0)
            return;

        // Schon Haltepunkt gesetzt?
        if ((nMarkers & 1<<m_nMarkerBreakpoint)!=0)
        {
            m_pSrcEdit->markerDelete(nLine, m_nMarkerBreakpoint);
        }
        else
        {
            m_pSrcEdit->markerAdd(nLine, m_nMarkerBreakpoint);
        }
    }
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::cursorMoved(int nLine, int nIndex)
{
    m_pFileExplorer->setCursorInfo(nLine, nIndex);
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::indicatorClicked(int nLine, int nIndex, Qt::KeyboardModifiers state)
{
    qDebug() << "indicatorClicked(" << nLine << "," << nIndex << ", " << state << ")";
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyFileModified(const IFile *pFile)
{
    // Diese Komponente löst den Event aus, der Inhalt von pFile
    // wurde bereite in updateFile aktualisiert.
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyFileActivate(const IFile *pFile)
{
    deleteMarker(tmHIGHLIGHT);
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren des angezeigten Dateiinhaltes. */
void FrmSourceEdit::notifyFileLoad(const IFile *pFile)
{
    std::size_t sz = pFile->getNumLines();
    QString sFile;
    for (std::size_t i=0; i<sz; ++i)
    {
        sFile += pFile->getLine(i) + "\n";
    }
    //m_pSrcEdit->setText(sFile);
    //QString GetCorrectUnicode(const QByteArray & ba)
    //{
        
        QTextCodec::ConverterState state;
        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        QByteArray ba = sFile.toLocal8Bit();
        QString text = codec->toUnicode(ba.constData(), ba.size(), &state);
        if (state.invalidChars > 0)
        {
            text = QTextCodec::codecForName("GB2312")->toUnicode(ba);
        }
        else
        {
            text = sFile;
        }
        m_pSrcEdit->setText(text);
    //    return text;
    //}
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyBeforeFileSave(IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
/** \brief Markieren einer bestimmten Zeile.
    \param pFile File in dem die Zeile markiert werden soll
    \param nLine Zeilenindex (einsbasiert)
*/
void FrmSourceEdit::notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker)
{
    deleteMarker(tmHIGHLIGHT);

    int nLineIdx = nLine - 1;
    if (nLineIdx<0)
        return;

    switch(eMarker)
    {
    case tmHIGHLIGHT:
        // es können mehrere Zeilen hervorgehoben sein
        m_pSrcEdit->markerAdd(nLineIdx, m_nMarkerLine);
        m_vMarkedLines.push_back(nLineIdx);

        // Hack: Cursor zuerst auf ende, dann auf die zu markierende Zeile.
        // Damit wird sichergestellt, das die Markierte Zeile die erste
        // angezeigt Zeile ist.
        m_pSrcEdit->setCursorPosition(m_pFile->getLines().size()-1, 0);
        m_pSrcEdit->setCursorPosition(nLineIdx, 0);
        m_pSrcEdit->ensureCursorVisible();
        break;

    case tmERROR:
        // Alte Fehlermarkierung löschen
        if (m_nErrorLine!=-1)
        {
            // Es scheint ein Redrawproblem zu geben, wenn der
            // cursor nicht in der Zeile steht
//            m_pSrcEdit->setCursorPosition(m_nErrorLine, 0);
            m_pSrcEdit->markerDelete(m_nErrorLine, m_nMarkerError);
        }

        // Es kann nur eine Zeile als Fehler markiert sein
        m_pSrcEdit->markerAdd(nLineIdx, m_nMarkerError);
        m_nErrorLine = nLineIdx;
        break;

    case tmBREAKPOINT:
    default:
        break;
    }


}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyFileLinesChanged(const IFile *pFile)
{
    // Ignorieren: Diese Komponente löst den Event aus.
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyPathChanged(const IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::deleteMarker(ETextMarker eMarker)
{
    int flags = (int)eMarker;

    // Errormarker entfernen
    if ( (flags & tmERROR) != 0)
    {
        if (m_nErrorLine!=-1)
        {
            m_pSrcEdit->markerDelete(m_nErrorLine, m_nMarkerError);
        }
    }

    // Highlights entfernen
    if ( (flags & tmHIGHLIGHT) != 0)
    {
        for (int i=0; i<m_vMarkedLines.size(); ++i)
        {
            m_pSrcEdit->markerDelete(m_vMarkedLines[i], m_nMarkerLine);
        }
        m_vMarkedLines.clear();
    }

    //m_pSrcEdit->up->update();
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::mousePressEvent(QMouseEvent * event)
{
    qDebug() << "mousePressEvent";
    QWidget::mousePressEvent(event);
}

//-------------------------------------------------------------------------------------------------
IFile::ptr_type FrmSourceEdit::getFile()
{
    return m_pFile;
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren der Konfiguration des controls gemäß der globalen Einstellungen.
*/
void FrmSourceEdit::updateFromSettings()
{
    const Settings &settings = Settings::Instance();
    QFont font("Courier New", settings.getFontSize());
    QFontMetrics fontmetrics = QFontMetrics(font);
    m_pSrcEdit->setMarginWidth(0, (settings.hasLineNumbers()) ? fontmetrics.width("00000") :0);
    m_pSrcEdit->setFolding( (settings.hasSourceFolding()) ? QsciScintilla::BoxedTreeFoldStyle
                                                          : QsciScintilla::NoFoldStyle, 2);

    m_pSrcEdit->lexer()->setFont(QFont("Courier New", settings.getFontSize()));
    m_pSrcEdit->setTabWidth(settings.getTabIndent());
}



