#ifndef IMAINFRAME_H
#define IMAINFRAME_H

#include "FwdDecl.h"

//-------------------------------------------------------------------------------------------------
class IMainFrame
{
public:
    virtual QWidget* asWidget() = 0;
    virtual IScriptEngine* getScriptEngine() = 0;
    virtual IFileObserver* getProjectExplorer() = 0;
    virtual IConsole* getConsole() = 0;

//    void doSyntaxCheck(IFile *pFile) = 0;
//    virtual IFileObserver* getFileExplorer() = 0;
};

#endif // IMAINFRAME_H
