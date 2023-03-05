#ifndef WND_MAIN_H
#define WND_MAIN_H

//--- Standard includes ---------------------------------------------------------------------------
#include <vector>

//--- Qtlib includes ------------------------------------------------------------------------------
#include <QMainWindow>
#include <QSplitter>
#include <QSettings>
#include "Qsci/qsciscintilla.h"

//--- Luanda includes -----------------------------------------------------------------------------
#include "IProject.h"
#include "IMainFrame.h"
#include "ISettingsProvider.h"
#include "FrmProjectExplorer.h"
#include "FrmFileExplorer.h"
#include "FrmConsole.h"
#include "FrmInfo.h"
#include "DlgSettings.h"
#include "DlgAbout.h"
#include "QConsoleStreamBuffer.h"
#include "AsWorker.h"
#include "minimap.h"
//--- Lua bindings --------------------------------------------------------------------------------
//#include "luabind/AsWorker.h"


namespace Ui {
    class WndMain;
}

//-------------------------------------------------------------------------------------------------
class WndMain : public QMainWindow,
                public ISettingsProvider,
                public IMainFrame
{
    Q_OBJECT

public:
    explicit WndMain(QWidget *parent = 0);
    ~WndMain();

    //---------------------------------------------------------------------------------------------
    // IMainFrame implementierung
    //---------------------------------------------------------------------------------------------

    virtual QWidget* asWidget();
    virtual IScriptEngine* getScriptEngine();
    virtual IFileObserver* getProjectExplorer();
    virtual IConsole* getConsole();

private:
    Ui::WndMain *ui;
    FrmProjectExplorer *m_pFrmExplorer;
    FrmFileExplorer *m_pFrmFileExplorer;
    FrmInfo *m_pFrmInfo;
    FrmConsole *m_pFrmConsole;
    //MiniMap* m_miniMap;

    DlgSettings *m_pDlgSettings;
    DlgAbout *m_pDlgAbout;

    std::vector<IProject*> m_projects;
    QSplitter *m_pspLeft;
    QSplitter *m_pspMain;
    QSplitter* m_pspRight;

    QThread *m_thLua;
    AsWorker *m_pAsWorker;

    enum { MaxRecentFiles = 5 };
    QAction *m_recentFileActs[MaxRecentFiles];
    QMenu *m_menuRecentFiles;
    QStringList m_recentFiles;

    void resizeEvent(QResizeEvent *);
    void createRecentFileMenus();
    void updateRecentFileActions();
    void updateDebugActions(ELuaWorkerState eState);
    void addRecentFileAction(const QString &sFile);
    void openFile(QString sFile);

    // ISettingsProvide
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

signals:
    void doFile(IFile *pFile);

public slots:
    void closeFile();

private slots:
    void openRecentFile();

    void on_lua_error(QString sMsg);
    void on_lua_syntax_check_fail(const IFile *pFile, QString sMsg, int nLine);
    void on_lua_syntax_check_success(const IFile *pFile);

    void on_lua_functionCall();
    void on_lua_scriptError(const LuaException &exc);

    void on_lua_exec_in_main_thread(IAction *pAction);
    void on_lua_finished();

    void on_actionConsole_triggered();
    void on_actionPreferences_triggered();
    void on_actionQuit_triggered();
    void on_actionSave_triggered();
    void on_actionAbout_triggered();
    void on_actionOpenProject_triggered();
    void on_actionOpenFile_triggered();
    void on_actionRun_triggered();


    void on_actionStop_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_triggered();

    void slotQuit();
    void slotFind();
    void slotFindNext();
    void scrollMiniMap(int value);

private:
    std::streambuf *m_pConsoleStreamBuf;
    std::streambuf *m_pOriginalStreamBuf;
    QString text;
    QString docText;

};

#endif // WND_MAIN_H
