#include "AsWorker.h"
#include "Exceptions.h"

#include <QThread>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QMutexLocker>

//--- LUA includes --------------------------------------------------------------------------------

#include "IFile.h"
#include "Exceptions.h"
#include "Locker.h"

#include "../grammar/translator.hpp"
//-------------------------------------------------------------------------------------------------
AsWorker::AsWorker(IConsole *pConsole)
    :QObject(NULL)
    ,IScriptEngine()
    ,ISyncContext()
    ,m_pConsole(pConsole)
    ,m_mtxTasks()
    ,m_pSysVar(NULL)
    ,m_vTables()
{

    // Hier keine dynamische allokation, da diese im Hauptthread geschehen würde!
    if (m_pConsole==NULL)
        throw InternalError(tr("Can't create Lua worker with null console pointer"));

    //m_vLuaTables.push_back(new LuaTabMessageBox());


    init();
    initTables();

    splashScreen();
}

//-------------------------------------------------------------------------------------------------
AsWorker::~AsWorker()
{

}

//-------------------------------------------------------------------------------------------------
void AsWorker::doSyntaxCheck(const IFile *pFile)
{
    if (pFile!=NULL)
        emit checkSyntax(pFile);
}

//-------------------------------------------------------------------------------------------------
void AsWorker::doAction(IAction *pAction)
{
    if (pAction==NULL)
        return;

    // Perform an asynchronous action
    if (pAction->getType()==IAction::ASYNC)
    {
        emit execInMainThread(pAction);
    }
    else
    {
        ActionWaiter wait(pAction);
        emit execInMainThread(pAction);
    }
}

//-------------------------------------------------------------------------------------------------
void AsWorker::stop()
{
  
}

//-------------------------------------------------------------------------------------------------
/** \brief Ausführen von Lua code aus einen String.

    Diese Funktion wird für die Konsolenanwendung benötigt.
*/
void AsWorker::on_doString(const QString &sCmd)
{
    if (m_pConsole==NULL)
        return;

    qDebug("on_doString(\"%s\"); thread id: %d",
           sCmd.toStdString().c_str(),
           reinterpret_cast<int>(QThread::currentThreadId()));

    try
    {
        doString(sCmd, "command_line_chunk");
        emit finished();
    }
    catch(Exception &exc)
    {
        emit error(exc.getMessage());
    }
    catch(std::exception &exc)
    {
        emit error(exc.what());
    }
    catch(...)
    {
        emit error("Internal error: FrmConsole::executeCommand");
    }
}


//-------------------------------------------------------------------------------------------------
void AsWorker::on_doFile(IFile *pFile)
{
    if (m_pConsole==NULL || pFile==NULL)
        return;

    qDebug("on_doFile(%s); thread id: %d",
           pFile->getName().toStdString().c_str(),
           reinterpret_cast<int>(QThread::currentThreadId()));

    try
    {
        QVector<QString> vLines = pFile->getLines();
        QString sScript;
        for (int i=0; i<vLines.size(); ++i)
        {
            sScript += vLines[i];
        }

        doString(sScript, pFile->getName());
        emit finished();
    }
    catch(LuaException &exc)
    {
        exc.setFile(pFile);

        QString sMsg = QString("%1 in Line %2").arg(exc.getMessage())
                                               .arg(exc.getLine());
        emit error(sMsg);
    }
    catch(Exception &exc)
    {
        emit error(exc.getMessage());
    }
    catch(std::exception &exc)
    {
        emit error(exc.what());
    }
    catch(...)
    {
        emit error("Internal error: FrmConsole::executeCommand");
    }
}

//-------------------------------------------------------------------------------------------------
void AsWorker::on_doProject(const IProject *pProject)
{
}


//-------------------------------------------------------------------------------------------------
void AsWorker::on_checkFile(const IFile *pFile)
{
    if (m_pConsole==NULL || pFile==NULL)
        return;

    try
    {
        Q_ASSERT(pFile!=NULL);
        Locker lock(pFile);

    //    qDebug() << "syntaxCheck(" << pFile->getName() << ")";

        const QVector<QString> &vLines = pFile->getLines();
        QString sScript;
        for (int i=0; i<vLines.size(); ++i)
        {
            const QString &sLine = vLines[i];
            sScript += sLine;
        }

        syntaxCheck(sScript, pFile->getName());
        emit syntaxCheckSuccess(pFile);
    }
    catch(LuaException &exc)
    {
        exc.setFile(pFile);

        QString sMsg = QString("%1 in Line %2").arg(exc.getMessage())
                                               .arg(exc.getLine());
        emit syntaxCheckFail(pFile, sMsg, (int)exc.getLine());
    }
    catch(Exception &exc)
    {
        emit syntaxCheckFail(pFile, exc.getMessage(), -1);
    }
    catch(std::exception &exc)
    {
        emit syntaxCheckFail(pFile, exc.what(), -1);
    }
    catch(...)
    {
        emit syntaxCheckFail(pFile, "Internal error: FrmConsole::executeCommand", -1);
    }
}

//-------------------------------------------------------------------------------------------------
void AsWorker::on_checkProject(const IProject *pProject)
{
}


//-------------------------------------------------------------------------------------------------
void AsWorker::init()
{

}

//-------------------------------------------------------------------------------------------------
void AsWorker::initTables()
{

}

//-------------------------------------------------------------------------------------------------
void AsWorker::splashScreen()
{
    if (m_pConsole==NULL)
        return;

    m_pConsole->addLine(" (C) 2021 jhl   http://www.jihualab.ac.cn/");
    m_pConsole->addLine("");
    m_pConsole->addLine(getCopyright());
    m_pConsole->addLine("");

}

//-------------------------------------------------------------------------------------------------
QString AsWorker::getVersion() const
{
    return QString("Lua %1.%2.%3").arg(1)
                                  .arg(0)
                                  .arg(0);
}

//-------------------------------------------------------------------------------------------------
QString AsWorker::getCopyright() const
{
    return QString("\n");//LUA_COPYRIGHT"\n"LUA_AUTHORS
}

//-------------------------------------------------------------------------------------------------
AsWorker& AsWorker::operator<<(const ILuaValue &arg)
{
  //arg.Push(m_luaState);
  return *this;
}

//-------------------------------------------------------------------------------------------------
AsWorker& AsWorker::operator>>(ILuaValue &arg)
{
  //arg.Pop(m_luaState);
  return *this;
}

//-------------------------------------------------------------------------------------------------
void AsWorker::setVariable(QString sName, ILuaValue &type)
{
  //type.Push(m_luaState);
  //lua_setglobal(m_luaState, sName.toUtf8().constData());
}

//-------------------------------------------------------------------------------------------------
void AsWorker::syntaxCheck(const QString &sLuaCode, const QString &sChunkName)
{
   
}

//-------------------------------------------------------------------------------------------------
void AsWorker::checkLuaError(int errc)
{
    if (!errc)
        return;
}

//-------------------------------------------------------------------------------------------------
void AsWorker::doString(const QString &sLuaCode, const QString &sChunkName)
{
    //m_luaState->stop_now = 0;

    syntaxCheck(sLuaCode, sChunkName);

    Language::Translator translator;
    translator.parse(sLuaCode);
    //checkLuaError(lua_pcall(m_luaState, 0, 0, 0));
}
