#include "QCommandPrompt.h"
#include "Utils.h"

//--- QT includes ---------------------------------------------------------------------------------
#include <QMutexLocker>
#include <QTimer>

//-------------------------------------------------------------------------------------------------
QCommandPrompt::QCommandPrompt(QWidget *parent)
    :QPlainTextEdit(parent)
    ,m_sPrompt("Lua")
    ,m_sPromptChar(">")
    ,m_vHistory()
    ,m_vLineQueue()
    ,m_pTimerQueue(new QTimer(this))
    ,m_font()
    ,m_mtxLineQueue()
    ,m_colDefault(Qt::darkBlue)
    ,m_nHistPos(0)
    ,m_nMaxLines(200)
    ,m_nMaxHist(5)
    ,m_nPromptPos()
    ,m_nTimerInterval(50)
    ,m_nBlockSize(200)
    ,m_bIsMuted(false)
{
    setAcceptDrops(true);                      // drops will be accepted (filenames and commands)
    setUndoRedoEnabled(false);                 // undo is not necessary in a console
    setTabChangesFocus(false);                 // tab will be needed for auto completion
    setLineWrapMode(QPlainTextEdit::NoWrap);

    m_pTimerQueue->setSingleShot(false);
    m_pTimerQueue->start(m_nTimerInterval);
    connect(m_pTimerQueue, SIGNAL(timeout()), this, SLOT(writeQueue()));

/*
    QStringList vWordList;
    vWordList.push_back("abcd");
    vWordList.push_back("efgh");
    vWordList.push_back("aaaaaa");

    m_pCompleter = new QCompleter(vWordList);
    m_pCompleter->setCaseSensitivity(Qt::CaseSensitive); //Make caseInsensitive selection
    m_pCompleter->setCompletionMode(QCompleter::InlineCompletion); //Used to enable in line searching

    this->setCompleter(m_pCompleter);
*/

    document()->setMaximumBlockCount(m_nMaxLines);
}

//-------------------------------------------------------------------------------------------------
QCommandPrompt::~QCommandPrompt()
{}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::setPrompt(QString sPrompt, QString sPromptChar)
{
    m_sPrompt = sPrompt + sPromptChar + " ";
}

//-------------------------------------------------------------------------------------------------
QString QCommandPrompt::getPrompt() const
{
    return m_sPrompt;
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::setOutputInterval(int nInterval)
{
    m_nTimerInterval = nInterval;
    m_pTimerQueue->stop();
    m_pTimerQueue->start(m_nTimerInterval);
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::setOutputBlockSize(int nLines)
{
    m_nBlockSize = nLines;
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::setMaxLines(int nLines)
{
    m_nMaxLines = nLines;
    document()->setMaximumBlockCount(m_nMaxLines);
}

//-------------------------------------------------------------------------------------------------
/** \brief Festlegen der Größe der History.
*/
void QCommandPrompt::setMaxHistSize(int nMaxHist)
{
    m_nMaxHist = nMaxHist;

    while (m_vHistory.size() > m_nMaxHist)
    {
        m_vHistory.removeLast();
    }
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::mute(bool bStat)
{
    m_bIsMuted = bStat;
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::clear()
{
    QMutexLocker lock(&m_mtxLineQueue);

    m_vHistory.clear();
    m_vLineQueue.clear();
    QPlainTextEdit::clear();
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::clearHistory()
{
    m_vHistory.clear();
}

//-------------------------------------------------------------------------------------------------
/** \brief Ändern der Textgröße der Console.
*/
void QCommandPrompt::setFontSize(int nSize)
{
    QFont font(this->font());
    font.setPixelSize(nSize);
    setFont(font);
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::addLine(QString sText)
{
    addLine(sText, Qt::black);
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::addLine(QString sText, QColor col)
{
    if (m_bIsMuted)
        return;

    QMutexLocker lock(&m_mtxLineQueue);

    m_vLineQueue.enqueue(qMakePair(sText, col));
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::clearQueue()
{
    QMutexLocker lock(&m_mtxLineQueue);
    m_vLineQueue.clear();
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::writeQueue()
{
    QMutexLocker lock(&m_mtxLineQueue);
    int nNum = std::min(m_nBlockSize, m_vLineQueue.count());
    for (int i=0; i<nNum; ++i)
    {
        QPair<QString, QColor> p = m_vLineQueue.dequeue();
        write(p.first, p.second);
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Anhängen einer Zeile ans Ende.

  Am Ende der Ausgabe wird immer ein Newline + Prompt ausgegeben!
*/
void QCommandPrompt::write(QString sMsg, QColor /*col*/)
{
    // Überprüfen, ob die Zeile mit einem Prompt anfängt
    QTextCursor tc = textCursor();
    tc.movePosition(QTextCursor::StartOfLine);
    tc.select(QTextCursor::LineUnderCursor);
    tc.removeSelectedText();
    setTextCursor(tc);

    // old: simple text
    insertPlainText(sMsg + "\n" + m_sPrompt);
/*
    // colored version
    QBrush brush(Qt::SolidPattern);
    brush.setColor(col);

    QTextCharFormat fmt;
    fmt.setForeground(brush);
    tc.insertText(sMsg + "\n", fmt);

    brush.setColor(m_colDefault);
    fmt.setForeground(brush);
    tc.insertText(m_sPrompt, fmt);
*/
    m_nPromptPos = tc.position();

    ensureCursorVisible();
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::clearLineExceptPrompt()
{
    QTextCursor tc = textCursor();
    tc.setPosition(m_nPromptPos, QTextCursor::MoveAnchor);
    tc.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    tc.removeSelectedText();

    tc.movePosition(QTextCursor::End);
    setTextCursor(tc);
}

//-------------------------------------------------------------------------------------------------
void QCommandPrompt::keyPressEvent(QKeyEvent *e)
{
    // Wenn Enter gedrückt wird, wird die Eingabe als Kommando interpretiert
    switch(e->key())
    {
    case Qt::Key_Return:
        {
            // Alles zwischen Promptposition und dem Textende ist das Kommando
            QString sAll = toPlainText();
            QString sCmd = sAll.right(sAll.count() - m_nPromptPos);

            if (sCmd.length()>0 && (m_vHistory.size()==0 || m_vHistory.back()!=sCmd) )
            {
                m_vHistory.push_back(sCmd);

                while (m_vHistory.size() > m_nMaxHist)
                    m_vHistory.removeFirst();

                m_nHistPos = m_vHistory.size() - 1;
            }

            sCmd = sCmd.trimmed();
            if (!sCmd.isEmpty())
            {
                addLine(getPrompt() + sCmd.trimmed());
                emit commandInput(sCmd);
            }

            // Textcursor ans Ende versetzen
            QTextCursor tc = textCursor();
            tc.movePosition(QTextCursor::End);
            setTextCursor(tc);
        }
        break;

    case Qt::Key_Up:
    case Qt::Key_Down:
        if (m_vHistory.size()==0)
            break;

        clearLineExceptPrompt();
        insertPlainText(m_vHistory[m_nHistPos]);

        m_nHistPos = m_nHistPos + ((e->key()==Qt::Key_Up) ? -1 : 1);
        m_nHistPos = Utils::clamp(0, m_vHistory.size()-1, m_nHistPos);
        break;

    case Qt::Key_Home:
        {
            QTextCursor tc = textCursor();
            Qt::KeyboardModifiers mod = e->modifiers();
            if (mod & Qt::ShiftModifier)
                tc.setPosition(m_nPromptPos, QTextCursor::KeepAnchor);
            else
                tc.setPosition(m_nPromptPos, QTextCursor::MoveAnchor);

            setTextCursor(tc);

        }
        break;

    case Qt::Key_Backspace:
    case Qt::Key_Left:
        {
            int nPos = textCursor().position();
            if (nPos > m_nPromptPos)
                QPlainTextEdit::keyPressEvent(e);
        }
        break;

    default:
        {
            int nPos = textCursor().position();
            if (nPos < m_nPromptPos)
            {
                QTextCursor tc = textCursor();
                tc.movePosition(QTextCursor::End);
                setTextCursor(tc);
            }

            QPlainTextEdit::keyPressEvent(e);
        }
    }
}
