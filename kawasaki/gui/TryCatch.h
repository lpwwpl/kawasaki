#ifndef TRYCATCH_H
#define TRYCATCH_H

//--- Standard includes ---------------------------------------------------------------------------
#include <stdexcept>

//--- Qt lib includes -----------------------------------------------------------------------------
#include <QMessageBox>

//--- Instant Lua framework -----------------------------------------------------------------------
#include "Exceptions.h"


#define TRY  \
        try

#define CATCH                                                \
    catch(const Exception &exc)                              \
    {                                                        \
        QMessageBox msgBox;                                  \
        msgBox.setText(exc.getMessage());                    \
        msgBox.exec();                                       \
    }                                                        \
    catch(std::exception &exc)                               \
    {                                                        \
        QMessageBox msgBox;                                  \
        msgBox.setText(exc.what());                          \
        msgBox.exec();                                       \
    }                                                        \
    catch(...)                                               \
    {                                                        \
        QMessageBox msgBox;                                  \
        msgBox.setText("Internal error");                    \
        msgBox.exec();                                       \
    }

#endif // TRYCATCH_H
