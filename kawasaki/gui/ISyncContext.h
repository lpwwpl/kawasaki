#ifndef ISYNCCONTEXT_H
#define ISYNCCONTEXT_H

#include "FwdDecl.h"


//-------------------------------------------------------------------------------------------------
/** \brief Interface für klassen, die Aktionen im Kontext des Hauptthreads ausführen können. */
class ISyncContext
{
public:

    virtual void doAction(IAction *pAction) = 0;
};

#endif // ISYNCCONTEXT_H
