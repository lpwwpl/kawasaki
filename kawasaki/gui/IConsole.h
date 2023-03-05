#ifndef ICONSOLE_H
#define ICONSOLE_H

#include <QColor>
#include <QString>


//-------------------------------------------------------------------------------------------------
class IConsole
{
public:
    virtual void addLine(QString sText, QColor col) = 0;
    virtual void addLine(QString sText) = 0;
    virtual void clearQueue() = 0;
};

#endif // ICONSOLE_H
