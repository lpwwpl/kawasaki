#ifndef FRMPROJECTVIEW_H
#define FRMPROJECTVIEW_H

//--- Qtlib includes ------------------------------------------------------------------------------
#include <QWidget>
#include <QDropEvent>

//--- luanda framework ----------------------------------------------------------------------------
#include "IFile.h"
#include "ISettingsProvider.h"
#include "Types.h"


namespace Ui {
    class FrmFileExplorer;
}

//-------------------------------------------------------------------------------------------------
class FrmFileExplorer : public QWidget,
                        public ISettingsProvider,
                        public IFileObserver
{
    Q_OBJECT

public:
    explicit FrmFileExplorer(IMainFrame *pWndMain);
    ~FrmFileExplorer();

    void addFile(IFile::ptr_type pFile);
    void saveAll(bool bModifiedOnly);
    void saveActiveFileAs(const QString &sFile);

    void dropEvent(QDropEvent *evt);
    void dragEnterEvent(QDragEnterEvent *event);
    void setCursorInfo(int nLine, int nIndex);

    void markActiveFileError(int nLine, const QString &sMsg);

    IFile* getActiveFile() const;

    // ISettingsprovider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

    // IFileObserver
    virtual void notifyFileActivate(const IFile *pFile);
    virtual void notifyFileLoad(const IFile *pFile);
    virtual void notifyBeforeFileSave(IFile *pFile);
    virtual void notifyFileModified(const IFile *pFile);
    virtual void notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker);
    virtual void notifyFileLinesChanged(const IFile *pFile);
    virtual void notifyPathChanged(const IFile *pFile);
    FrmSourceEdit* getActiveSourceEdit();

private:
    Ui::FrmFileExplorer *ui;
    IMainFrame *m_pWndMain;

    IFile* findFile(const QString &sPath);

    int getTabIndex(const IFile *pFile);
    FrmSourceEdit* getSourceEdit(const IFile *pFile);

    FrmSourceEdit* m_pSrcEdit;

signals:
    void checkFile(const IFile *pFile);
    void closeFileExplorer();

private slots:
    void on_actionClose_All_But_This_triggered();
    void on_actionClose_triggered();
    void on_tcProject_tabCloseRequested(int index);
    void on_tcProject_currentChanged(QWidget *arg1);
};

#endif // FRMPROJECTVIEW_H
