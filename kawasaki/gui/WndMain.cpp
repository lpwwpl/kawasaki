#include "WndMain.h"
#include "ui_WndMain.h"

#include <iostream>

//--- QTlib includes ------------------------------------------------------------------------------
#include <QSplitter>
#include <QSettings>
#include <QFileDialog>
#include <QDebug>
#include <QThread>
#include <QScrollBar>
//-------------------------------------------------------------------------------------------------
#include "Settings.h"
#include "FileLua.h"
#include "DlgSettings.h"
#include "DlgNewFile.h"
#include "ProjectLua.h"
#include "Exceptions.h"
#include "TryCatch.h"
#include "FrmSourceEdit.h"
#include <QShortcut>
#include "searchandreplace.h"
//#include "luabind/AsWorker.h"

//-------------------------------------------------------------------------------------------------
WndMain::WndMain(QWidget *parent)
    :QMainWindow(parent)
    ,ISettingsProvider()
    ,ui(new Ui::WndMain)
    ,m_pFrmExplorer(NULL)
    ,m_pFrmFileExplorer(NULL)
    ,m_pFrmInfo(NULL)
    ,m_pFrmConsole(NULL)
    ,m_pDlgSettings(NULL)
    ,m_projects()
    ,m_pspLeft(NULL)
    ,m_pspMain(NULL)
    ,m_thLua(NULL)
    ,m_pConsoleStreamBuf(NULL)
{
    ui->setupUi(this);
    new QShortcut(QKeySequence::Quit, this, SLOT(slotQuit()));
    new QShortcut(QKeySequence::Find, this, SLOT(slotFind()));
    new QShortcut(QKeySequence::FindNext, this, SLOT(slotFindNext()));

    // Explorer Fenster anlegen, die Reihenfolge ist wichtig, da gegenseitige Abhängigkeiten
    // bestehen!
    m_pFrmExplorer = new FrmProjectExplorer(this);
    m_pFrmExplorer->setMaximumWidth(500);

    m_pFrmFileExplorer = new FrmFileExplorer(this);

    // Weitere Frames und Dialoge
    m_pFrmInfo = new FrmInfo(this);
    m_pFrmConsole = new FrmConsole(this);
    m_pDlgSettings = new DlgSettings(this);
    m_pDlgAbout = new DlgAbout(this);
    //m_miniMap = new MiniMap(this);
    //m_miniMap->setMaximumWidth(720);
    // Linkes Splitterfenster
    m_pspLeft = new QSplitter(Qt::Vertical, this);
    m_pspLeft->addWidget(m_pFrmFileExplorer);
    m_pspLeft->addWidget(m_pFrmConsole);
    
    
    //m_pspRight = new QSplitter(Qt::Vertical, this);
    //m_pspRight->addWidget(m_miniMap);

    // Splitter einrichtenQDockWidget::DockWidgetFloat
    m_pspMain = new QSplitter(Qt::Horizontal, this);
    m_pspMain->addWidget(m_pFrmExplorer);
    m_pspMain->addWidget(m_pspLeft);
    //m_pspMain->addWidget(m_pspRight);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(m_pspMain);
    vbox->setMargin(0);
    ui->frmMain->setLayout(vbox);

    createRecentFileMenus();

    // Einlesen der Settings (letzter Schritt!)
    Settings &s = Settings::Instance();
    s.addProvider(this);
    s.addProvider(m_pFrmFileExplorer);
    s.addProvider(m_pFrmExplorer);
    s.addProvider(m_pFrmConsole);
    s.addProvider(m_pDlgSettings);
    //s.addProvider(m_miniMap);
    s.readSettings();

    // Umleiten der Standardausgabe in die Konsole, speichern des Originalstreams
    m_pConsoleStreamBuf  = new console_streambuf(m_pFrmConsole->getIConsole());
    m_pOriginalStreamBuf = std::cout.rdbuf(m_pConsoleStreamBuf);

    qDebug("Main thread id: %d", reinterpret_cast<int>(QThread::currentThreadId()));

    // Starten des Lua threads
    m_thLua = new QThread();
    m_pAsWorker = new AsWorker(m_pFrmConsole->getConsole());
    m_pAsWorker->moveToThread(m_thLua);

   connect(m_pAsWorker, SIGNAL(error(QString)),
            this,         SLOT(on_lua_error(QString)));

    connect(m_pAsWorker, SIGNAL(finished()),
            this,         SLOT(on_lua_finished()));

    connect(m_pAsWorker, SIGNAL(syntaxCheckFail(const IFile*, QString, int)),
            this,         SLOT(on_lua_syntax_check_fail(const IFile*, QString, int)));

    connect(m_pAsWorker, SIGNAL(syntaxCheckSuccess(const IFile*)),
            this,         SLOT(on_lua_syntax_check_success(const IFile*)));

    connect(m_pAsWorker, SIGNAL(execInMainThread(IAction*)),
            this,         SLOT(on_lua_exec_in_main_thread(IAction*)));

    connect(m_pFrmConsole->getConsole(), SIGNAL(commandInput(const QString&)), m_pAsWorker, SLOT(on_doString(const QString&)));
    connect(m_pFrmFileExplorer, SIGNAL(checkFile(const IFile*)), m_pAsWorker, SLOT(on_checkFile(const IFile*)));
    connect(this, SIGNAL(doFile(IFile*)), m_pAsWorker, SLOT(on_doFile(IFile*)));


    connect(m_pFrmFileExplorer, SIGNAL(closeFileExplorer()), this, SLOT(closeFile()));

    m_thLua->start();


}

//-------------------------------------------------------------------------------------------------
WndMain::~WndMain()
{
    delete ui;
    delete m_pConsoleStreamBuf;

    // Restore original cout stream buffer
    std::cout.rdbuf(m_pOriginalStreamBuf);
}

void WndMain::closeFile()
{
    m_pFrmExplorer->Reset();
    //m_miniMap->clear();
}

void WndMain::scrollMiniMap(int value)
{
    //m_miniMap->verticalScrollBar()->setValue(value );
}
void WndMain::slotFind()
{
    SearchAndReplace sar(m_pFrmFileExplorer->getActiveSourceEdit()->GetSrcEdit(), this);
    sar.exec();
}

void WndMain::slotFindNext()
{
    m_pFrmFileExplorer->getActiveSourceEdit()->GetSrcEdit()->findNext();
}

//-------------------------------------------------------------------------------------------------
// IMainFrame
//-------------------------------------------------------------------------------------------------

QWidget* WndMain::asWidget()
{
    return this;
}

//-------------------------------------------------------------------------------------------------
IScriptEngine* WndMain::getScriptEngine()
{
    return m_pAsWorker;// m_pAsWorker;
}

//-------------------------------------------------------------------------------------------------
IFileObserver* WndMain::getProjectExplorer()
{
    Q_ASSERT(m_pFrmExplorer!=NULL);
    return m_pFrmExplorer;
}

//-------------------------------------------------------------------------------------------------
IConsole* WndMain::getConsole()
{
    return m_pFrmConsole->getIConsole();
}

//-------------------------------------------------------------------------------------------------
void WndMain::createRecentFileMenus()
{
    for (int i = 0; i < MaxRecentFiles; ++i)
    {
        m_recentFileActs[i] = new QAction(this);
        m_recentFileActs[i]->setVisible(false);
        connect(m_recentFileActs[i],
                SIGNAL(triggered()),
                this,
                SLOT(openRecentFile()));
    }


    for (int i = 0; i < MaxRecentFiles; ++i)
        ui->menuRecentFiles->addAction(m_recentFileActs[i]);
}


//-------------------------------------------------------------------------------------------------
void WndMain::resizeEvent(QResizeEvent *)
{
    if (m_pFrmInfo->isVisible())
        m_pFrmInfo->center();
}

//-------------------------------------------------------------------------------------------------
/** \brief Opens a new Lua File in the editor.
*/
void WndMain::on_actionOpenFile_triggered()
TRY
{
    QString sFile = QFileDialog::getOpenFileName(this,
                                                tr("Select File of project to open"),
                                                m_pFrmExplorer->getProjectPath().absolutePath(),
                                                tr("LUA Files (*.as *.pg)"));

    if (sFile.length()>0)
    {
        openFile(sFile);
    }
}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Öffnen eines Projektverzeichnisses.
*/
void WndMain::on_actionOpenProject_triggered()
TRY
{
    // Es gibt drei Möglichkeiten für das Projektöffnen
    // 1.) Angeben eines Verzeichnisses, Wenn im Verzeichnis ein Projektfile liegt, wird dieses geladen
    // 2.) Anwählen eines Projektfiles
    Settings &settings = Settings::Instance();
    QString sPath = QFileDialog::getExistingDirectory(this,
                                                      tr("Select the project directory"),
                                                      settings.getProjectPath(),
                                                      QFileDialog::ShowDirsOnly);
    if (!sPath.isEmpty())
    {
        QSharedPointer<ProjectLua> pProject(new ProjectLua(sPath));
    }
}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Opens a new file in the editor. */
void WndMain::openFile(QString sFile)
{
    if (sFile.isNull() || sFile.isEmpty())
        return;

    IFile::ptr_type pFile = FileLua::create(sFile);
    m_pFrmFileExplorer->addFile(pFile);

    connect(static_cast<QsciScintilla*>(m_pFrmFileExplorer->getActiveSourceEdit()->GetSrcEdit())->verticalScrollBar(), &QScrollBar::valueChanged, this, &WndMain::scrollMiniMap);

    QsciDocument document = static_cast<QsciScintilla*>(m_pFrmFileExplorer->getActiveSourceEdit()->GetSrcEdit())->document();
    ///////////m_miniMap->setDocument(document);
    pFile->load();

    addRecentFileAction(sFile);
}

//-------------------------------------------------------------------------------------------------
/** \brief Speichert all offenen Dateien ab, die als geändert markiert sind. */
void WndMain::on_actionSave_triggered()
TRY
{
    m_pFrmInfo->setTitle("Saving files");
    m_pFrmInfo->setSubTitle("please wait...");
    m_pFrmInfo->show(2000);
    m_pFrmFileExplorer->saveAll(true);
}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Speichert die geöffnete Datei unter einem anderen Namen ab. */
void WndMain::on_actionSave_as_triggered()
TRY
{
    QString sFile = QFileDialog::getSaveFileName(this,
                                                 tr("Save file as"),
                                                 m_pFrmExplorer->getProjectPath().absolutePath(),
                                                 tr("LUA Files (*.as)"));

    if (sFile.length()>0)
    {
        m_pFrmFileExplorer->saveActiveFileAs(sFile);
        addRecentFileAction(sFile);
    }

}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Quit the application.
*/
void WndMain::on_actionQuit_triggered()
TRY
{
    Settings::Instance().writeSettings();
    QApplication::exit(0);
}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Open the settings window. */
void WndMain::on_actionPreferences_triggered()
TRY
{
    m_pDlgSettings->exec();
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_actionAbout_triggered()
TRY
{
    m_pDlgAbout->exec();
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::readSettings(QSettings &settings)
{
    settings.beginGroup("MainWindow");

    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();

    QByteArray state;
    state = settings.value("state", QByteArray()).toByteArray();
    restoreState(state);

    state = settings.value("splitter_main", QByteArray()).toByteArray();
    m_pspMain->restoreState(state);

    state = settings.value("splitter_left", QByteArray()).toByteArray();
    m_pspLeft->restoreState(state);

    resize(size);
    move(pos);

    m_recentFiles = settings.value("recent_file_list").toStringList();

    m_pFrmConsole->setVisible(settings.value("console_visibility", true).toBool());
    m_pFrmExplorer->setVisible(settings.value("project_explorer_visibility", true).toBool());

    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void WndMain::writeSettings(QSettings &settings)
{
    settings.beginGroup("MainWindow");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("state", saveState());
    settings.setValue("splitter_main", m_pspMain->saveState());
    settings.setValue("splitter_left", m_pspLeft->saveState());
    settings.setValue("console_visibility", m_pFrmConsole->isVisible());
    settings.setValue("project_explorer_visibility", m_pFrmExplorer->isVisible());
    settings.setValue("recent_file_list", m_recentFiles);
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren des Hauptfensters nach einlesen bzw. Ändern der Programmeinstellungen.

  Aktualisiert die recent File Liste.
*/
void WndMain::updateFromSettings()
{
    updateRecentFileActions();
}

//-------------------------------------------------------------------------------------------------
/** \brief Anzeigen bzw. Verstecken des Konsolenframes.
  */
void WndMain::on_actionConsole_triggered()
TRY
{
    if (m_pFrmConsole->isVisible())
        m_pFrmConsole->hide();
    else
        m_pFrmConsole->show();
}
CATCH

//-------------------------------------------------------------------------------------------------
/** \brief Ein Fehler ist aufgetreten.

    Lua wurde bereits angehalten.
*/
void WndMain::on_lua_error(QString sErr)
TRY
{
    IConsole *pConsole = m_pFrmConsole->getConsole();
    if (pConsole!=NULL)
    {
        // Zurücksetzten der queue, nur die Fehlermeldung wird angezeigt.
        pConsole->clearQueue();
        pConsole->addLine(sErr, Qt::red);
        qDebug("on_lua_error(%s); thread id: %d", sErr.toStdString().c_str(), reinterpret_cast<int>(QThread::currentThreadId()));
    }
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_exec_in_main_thread(IAction *pAction)
TRY
{
    if (pAction!=NULL)
        pAction->execute_();
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::updateDebugActions(ELuaWorkerState eState)
{
    switch(eState)
    {
    case lsEXECUTING:
            ui->actionRun->setEnabled(false);
            ui->actionStop->setEnabled(true);
            ui->actionStepOut->setEnabled(false);
            ui->actionStepOver->setEnabled(false);
            ui->actionStepInto->setEnabled(false);
            break;

    case lsDEBUGGING:
            ui->actionRun->setEnabled(false);
            ui->actionStop->setEnabled(true);
            ui->actionStepOut->setEnabled(false);
            ui->actionStepOver->setEnabled(false);
            ui->actionStepInto->setEnabled(false);
            break;

    case lsWAITING:
            ui->actionRun->setEnabled(true);
            ui->actionStop->setEnabled(false);
            ui->actionStepOut->setEnabled(true);
            ui->actionStepOver->setEnabled(true);
            ui->actionStepInto->setEnabled(true);
            break;
    }
}

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_finished()
TRY
{
    updateDebugActions(lsWAITING);
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_syntax_check_fail(const IFile *pFile, QString sErr, int nLine)
TRY
{
    m_pFrmConsole->getConsole()->addLine(sErr);
    m_pFrmFileExplorer->markActiveFileError(nLine, sErr);
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_syntax_check_success(const IFile *pFile)
TRY
{
    qDebug() << "on_lua_syntax_check_success(" << pFile->getName() << "): Syntax check successfull\n";
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_functionCall()
TRY
{}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_scriptError(const LuaException &exc)
TRY
{
    const IFile *pFile = exc.getFile();
    if (pFile==NULL)
        return;

    pFile->activate();
    pFile->navigateToLine(exc.getLine(), tmERROR);
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString sFile = action->data().toString();
        openFile(sFile);
    }
}

//-------------------------------------------------------------------------------------------------
void WndMain::addRecentFileAction(const QString &sFile)
{
    // update recent file list
    m_recentFiles.removeAll(sFile);
    m_recentFiles.prepend(sFile);

    while (m_recentFiles.size() > MaxRecentFiles)
        m_recentFiles.removeLast();

    updateRecentFileActions();
}

//-------------------------------------------------------------------------------------------------
void WndMain::updateRecentFileActions()
{
    int nRecentFiles = qMin(m_recentFiles.size(), (int)MaxRecentFiles);
    for (int i = 0; i < nRecentFiles; ++i)
    {
// Nur Dateiname:
//        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(m_recentFiles[i]).fileName());
// Dateiname + Pfad:
        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(m_recentFiles[i]).filePath());
        m_recentFileActs[i]->setText(text);
        m_recentFileActs[i]->setData(m_recentFiles[i]);
        m_recentFileActs[i]->setVisible(true);
    }

    for (int j = nRecentFiles; j < MaxRecentFiles; ++j)
        m_recentFileActs[j]->setVisible(false);
}

//-------------------------------------------------------------------------------------------------
void WndMain::on_actionRun_triggered()
TRY
{
    try
    {
        if (m_thLua==NULL)
            return;

        updateDebugActions(lsEXECUTING);
        IFile *pFile = m_pFrmFileExplorer->getActiveFile();
        if (pFile!=NULL)
        {
            emit doFile(pFile);
        }
    }
    catch(...)
    {
        updateDebugActions(lsWAITING);
        throw;
    }
}
CATCH

//-------------------------------------------------------------------------------------------------
void WndMain::on_actionStop_triggered()
TRY
{
    Q_ASSERT(m_pAsWorker!=NULL);

    if (m_pAsWorker!=NULL)
        m_pAsWorker->stop();
    updateDebugActions(lsWAITING);
}
CATCH


//-------------------------------------------------------------------------------------------------
void WndMain::on_actionNew_triggered()
TRY
{
    DlgNewFile dlgNewFile(NULL, Settings::Instance());
    int state = dlgNewFile.exec();
    if (state==QDialog::Accepted)
    {
        IFile::ptr_type pFile = FileLua::create(dlgNewFile.getFileName());
        m_pFrmFileExplorer->addFile(pFile);
    }

}
CATCH

void WndMain::slotQuit()
{

}
