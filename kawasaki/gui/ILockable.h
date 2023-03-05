#ifndef ILOCKABLE_H
#define ILOCKABLE_H


//-------------------------------------------------------------------------------------------------
/** \brief Interface für Dateien, die in Luanda angezeigt werden können.
*/
class ILockable
{
public:
    virtual void lock() const = 0;
    virtual void unlock() const = 0;
};

#endif // ILOCKABLE_H
