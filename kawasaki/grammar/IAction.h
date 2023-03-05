#ifndef IACTION_H
#define IACTION_H

//-------------------------------------------------------------------------------------------------
#include <QMutex>
#include <QWaitCondition>
#include <QVariant>

//-------------------------------------------------------------------------------------------------
class IAction
{
friend class ActionWaiter;

public:

    enum EActionType
    {
        SYNC,
        ASYNC
    };

    IAction(EActionType eType = IAction::SYNC);
    virtual ~IAction();
    //virtual void execute_impl() = 0;
    virtual QVariant Execute()=0;
    void execute_();
    void wait();
    EActionType getType() const;

public:
    mutable QMutex m_mtxAction;
    QWaitCondition m_wait;

private:
    EActionType    m_eType;
};

//-------------------------------------------------------------------------------------------------
class ActionWaiter
{
public:
    ActionWaiter(IAction *pAction);
   ~ActionWaiter();

private:
    ActionWaiter(const ActionWaiter&);
    ActionWaiter& operator=(const ActionWaiter&);

    IAction *m_pAction;
};

#endif // IACTION_H
