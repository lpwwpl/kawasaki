#include "IAction.h"

#include <cassert>
#include <QDebug>
#include <QThread>
#include <QMutexLocker>


//-------------------------------------------------------------------------------------------------
IAction::IAction(EActionType eType)
    :m_mtxAction()
    ,m_eType(eType)
{}

//-------------------------------------------------------------------------------------------------
IAction::~IAction()
{}

//-------------------------------------------------------------------------------------------------
IAction::EActionType IAction::getType() const
{
    return m_eType;
}

//-------------------------------------------------------------------------------------------------
void IAction::execute_()
{
    try
    {
        QMutexLocker lock(&m_mtxAction);
        Execute();

        if (m_eType==IAction::SYNC)
        {
            m_wait.wakeAll();
        }
    }
    catch(...)
    {
        if (m_eType==IAction::SYNC)
        {
            m_wait.wakeAll();
        }

        throw;
    }
}

//-------------------------------------------------------------------------------------------------
void IAction::wait()
{
    m_wait.wait(&m_mtxAction);
}

//-------------------------------------------------------------------------------------------------
// ActionWaiter
//-------------------------------------------------------------------------------------------------

ActionWaiter::ActionWaiter(IAction *pAction)
    :m_pAction(pAction)
{
    assert(m_pAction!=NULL);
    m_pAction->m_mtxAction.lock();
}

//-------------------------------------------------------------------------------------------------
ActionWaiter::~ActionWaiter()
{
    bool bStat = m_pAction->m_wait.wait(&m_pAction->m_mtxAction, 20000);
    if (!bStat)
    {
        qDebug("%d: FAIL:  Action waiter timeout: Wait for WaitCondition.", reinterpret_cast<int>(QThread::currentThreadId()));
    }

    m_pAction->m_mtxAction.unlock();
}
