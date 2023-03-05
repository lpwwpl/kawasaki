#ifndef ISYNCCONTEXT_H
#define ISYNCCONTEXT_H

#include "FwdDecl.h"


//-------------------------------------------------------------------------------------------------
/** \brief Interface f�r klassen, die Aktionen im Kontext des Hauptthreads ausf�hren k�nnen. */
class ISyncContext
{
public:

    virtual void doAction(IAction *pAction) = 0;
};

#endif // ISYNCCONTEXT_H
