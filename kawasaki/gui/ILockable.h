#ifndef ILOCKABLE_H
#define ILOCKABLE_H


//-------------------------------------------------------------------------------------------------
/** \brief Interface f�r Dateien, die in Luanda angezeigt werden k�nnen.
*/
class ILockable
{
public:
    virtual void lock() const = 0;
    virtual void unlock() const = 0;
};

#endif // ILOCKABLE_H
