#ifndef FRMSOURCEEDIT_H
#define FRMSOURCEEDIT_H

//--- QTLib includes ------------------------------------------------------------------------------
#include <QFileInfo>
#include <Qsci/qsciscintilla.h>

//--- luanda includes -----------------------------------------------------------------------------
#include "IFile.h"
#include "IFileObserver.h"
#include "FrmFileExplorer.h"
#include "Types.h"


//-------------------------------------------------------------------------------------------------
class FrmSourceEdit : public QWidget,
                      public IFileObserver
{
    Q_OBJECT

public:

    FrmSourceEdit(FrmFileExplorer *pParent, IFile::ptr_type pFile);
   ~FrmSourceEdit();

    // IFileObserver
    virtual void notifyFileActivate(const IFile *pFile);
    virtual void notifyFileModified(const IFile *pFile);
    virtual void notifyFileLoad(const IFile *pFile);
    virtual void notifyBeforeFileSave(IFile *pFile);
    virtual void notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker);
    virtual void notifyFileLinesChanged(const IFile *pFile);
    virtual void notifyPathChanged(const IFile *pFile);

    // von Widget reimplementiert
    virtual void mousePressEvent(QMouseEvent * event);

    // eigene Funktionen
    IFile::ptr_type getFile();
    void updateFromSettings();
    QsciScintilla* GetSrcEdit() { return m_pSrcEdit; }
signals:
    void checkFile(IFile*);

private slots:

    // für QScintilla
    void fileModified(bool bStat);
    void linesChanged();
    void cursorMoved(int,int);
    void indicatorClicked(int, int, Qt::KeyboardModifiers);
    void marginClicked(int margin, int line, Qt::KeyboardModifiers state);
    void textChanged();

private:
    QsciScintilla *m_pSrcEdit;
    IFile::ptr_type m_pFile;
    FrmFileExplorer *m_pFileExplorer;

    // Marker
    int m_nMarkerBreakpoint;
    int m_nMarkerCIP;
    int m_nMarkerLine;
    int m_nMarkerError;
    int m_nMarkerPotentialBreakpoint;

    QVector<int> m_vMarkedLines;
    int m_nErrorLine;

    // Indikatoren
    int m_nNumberIndicator;

    bool lineAcceptsBreakpoints(int nLine);
    void clearMarkedLines();
    void updateFile(bool bModifiedFlag);
    void updateBreakpointIndicators();
    void deleteMarker(ETextMarker eMarker);
};

#endif // FRMSOURCEEDIT_H
