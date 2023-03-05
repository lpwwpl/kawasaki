#ifndef FRMPROJECTEXPLORER_H
#define FRMPROJECTEXPLORER_H

//--- Qt lib framework ----------------------------------------------------------------------------
#include <QWidget>
#include <QDir>

//--- Luanda framework ----------------------------------------------------------------------------
#include "IFileObserver.h"
#include "ISettingsProvider.h"
#include "FwdDecl.h"


namespace Ui {
    class FrmProjectExplorer;
}

//-------------------------------------------------------------------------------------------------
class FrmProjectExplorer : public QWidget
                         , public ISettingsProvider
                         , public IFileObserver
{
    Q_OBJECT

public:
    explicit FrmProjectExplorer(IMainFrame *wndMain = 0);
    ~FrmProjectExplorer();

    const QDir& getProjectPath() const;
    void setProjectPath(QString sNewPath);

    // ISettingsProvider
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
    void Reset();

private slots:
    void on_tvOutline_itemSelectionChanged();

private:
    Ui::FrmProjectExplorer *ui;
    IMainFrame *m_pWndMain;
    QDir m_dirProjects;
    QSharedPointer<ScriptOutline> m_pScriptOutline;
    const IFile *m_pActiveFile;

    void initOutline();
    void updateOutline(const IFile *pFile);
};

#endif // FRMPROJECTEXPLORER_H
