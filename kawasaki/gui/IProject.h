#ifndef IPROJECT_H
#define IPROJECT_H

#include "Types.h"
#include <QString>


//-------------------------------------------------------------------------------------------------
/** \brief Eine Klasse, die ein Projekt repräsentiert.

  Projekte bestehen aus mindestens einem Lua file, die alle in Lua geladen werden
  müssen, da sie wechselseitige referenzen enthalten.
*/
class IProject
{
public:
    IProject();
    virtual ~IProject();

    virtual void addFile(const QString &sFileName) = 0;
    virtual void deleteFile(const QString &sFileName) = 0;
    virtual void open(const QString &sProject) = 0;
    virtual QString getName() const = 0;
};

#endif // IPROJECT_H
