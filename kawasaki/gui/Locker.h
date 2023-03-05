#ifndef LOCKER_H
#define LOCKER_H

#include "ILockable.h"

//-------------------------------------------------------------------------------------------------
class Locker
{
public:
    Locker(const ILockable *pLockable);
   ~Locker();

private:
    Locker(const Locker &);
    Locker& operator=(const Locker&);

    const ILockable *m_pLockable;
};

#endif // LOCKER_H
