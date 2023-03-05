#ifndef SETTINGS_H
#define SETTINGS_H

//--- Standard includes ---------------------------------------------------------------------------
#include <memory>

//--- QTLib includes ------------------------------------------------------------------------------
#include <QString>
#include <QSettings>
#include <QDir>
#include <QVector>

//--- luanda framework ----------------------------------------------------------------------------
#include "Types.h"
#include "ISettingsProvider.h"

//-------------------------------------------------------------------------------------------------
// Settings keys as used by the QSettings object
extern const QString keyShowLineNumbers;
extern const QString keyEnableSourceFolding;
extern const QString keyFontSize;
extern const QString keyTabIndent;
extern const QString keyProjectPath;

//-------------------------------------------------------------------------------------------------
class Settings
{
public:

    friend class std::auto_ptr<Settings>;
    static Settings& Instance();

    void addProvider(ISettingsProvider *pSettingsProvider);
    void writeSettings();
    void readSettings();
    void updateFromSettings();

    // Property getter
    bool hasSourceFolding() const;
    bool hasLineNumbers() const;
    int getFontSize() const;
    int getTabIndent() const;
    const QString& getProjectPath() const;

    // Property setter
    void setSourceFolding(bool bEnable);
    void setLineNumbers(bool bEnable);
    void setFontSize(int nSize);
    void setTabIndent(int nIndent);
    void setProjectPath(QString sPath);

private:

    static std::auto_ptr<Settings> s_pInst;

    Settings();
   ~Settings();

    mutable QSettings m_settings;

    bool m_bEnableLineNumbers;
    bool m_bEnableSourceFolding;
    int m_nFontSize;
    int m_nTabIndent;
    QString m_sProjectPath;

    QVector<ISettingsProvider*> m_vSettingsProvider;
};

#endif // SETTINGS_H
