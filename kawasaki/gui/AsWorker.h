#ifndef ASWORKER_H
#define ASWORKER_H

//--- QT-Library ----------------------------------------------------------------------------------
#include <QObject>
#include <QMutex>
#include <QSharedPointer>
#include <QString>
#include <QVector>

#include "FwdDecl.h"
#include "IConsole.h"
#include "IScriptEngine.h"
#include "ISyncContext.h"
#include "../grammar/symboltable.h"
#include "../grammar/IAction.h"
//--- LUA includes --------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
class AsWorker : public QObject,
                  public IScriptEngine,
                  public ISyncContext
{
    Q_OBJECT

public:
    explicit AsWorker(IConsole *pConsole);
    virtual ~AsWorker();

    AsWorker& operator<<(const ILuaValue &arg);
    AsWorker& operator>>(ILuaValue &arg);

    void setVariable(QString sName, ILuaValue &type);

    // IScriptEngine
    virtual void doSyntaxCheck(const IFile *pFile);
    virtual void stop();
    virtual QString getVersion() const;
    virtual QString getCopyright() const;

    // ISynchContext
    virtual void doAction(IAction *pAction);

signals:
    void finished();
    void error(QString sErr);
    void syntaxCheckFail(const IFile *pFile, QString sErr, int nLine);
    void syntaxCheckSuccess(const IFile *pFile);
    void checkSyntax(const IFile *pFile);
    void execInMainThread(IAction *pAction);

public slots:

    // Ausführung von Lua-Code
    void on_doString(const QString &script);
    void on_doFile(IFile *pFile);
    void on_doProject(const IProject *pProject);

    // Syntaxüberprüfung
    void on_checkFile(const IFile *pFile);
    void on_checkProject(const IProject *pProject);

private:
    IConsole *m_pConsole;
    QMutex m_mtxTasks;
    QSharedPointer<ILuaValue> m_pSysVar;
    SymbolTable* m_vTables;

    void init();
    void initTables();

    void splashScreen();

    void checkLuaError(int errc);
    void syntaxCheck(const QString &sLuaCode, const QString &sChunkName);
    void doString(const QString &sLuaCode, const QString &sChunkName);
};

#endif // LUAWORKER_H
