#include "Locker.h"
#include <QDebug>


//-------------------------------------------------------------------------------------------------
Locker::Locker(const ILockable *pLockable)
    :m_pLockable(pLockable)
{
    Q_ASSERT(pLockable!=0);
    pLockable->lock();
}

//-------------------------------------------------------------------------------------------------
Locker::~Locker()
{
    m_pLockable->unlock();
}
