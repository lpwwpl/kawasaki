#ifndef ISETTINGSPROVIDER_H
#define ISETTINGSPROVIDER_H

//--- QTLib includes ------------------------------------------------------------------------------
#include <QSettings>

//-------------------------------------------------------------------------------------------------
class ISettingsProvider
{
public:
    virtual void writeSettings(QSettings &settings) = 0;
    virtual void readSettings(QSettings &settings) = 0;
    virtual void updateFromSettings() = 0;
};

#endif // ISETTINGSPROVIDER_H
