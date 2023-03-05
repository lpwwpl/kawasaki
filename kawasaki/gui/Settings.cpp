#include "Settings.h"

//--- QTLib includes ------------------------------------------------------------------------------
#include <QApplication>

//-------------------------------------------------------------------------------------------------
const QString keyShowLineNumbers     = "showLineNumbers";
const QString keyEnableSourceFolding = "enableSourceFolding";
const QString keyFontSize            = "fontSize";
const QString keyTabIndent           = "tabIndent";
const QString keyProjectPath         = "project_path";

//-------------------------------------------------------------------------------------------------
std::auto_ptr<Settings> Settings::s_pInst;

//-------------------------------------------------------------------------------------------------
Settings& Settings::Instance()
{
    if (s_pInst.get()==NULL)
    {
        s_pInst.reset(new Settings);
    }

    return *s_pInst;
}

//-------------------------------------------------------------------------------------------------
Settings::Settings()
    :m_settings(QSettings::IniFormat, QSettings::UserScope, "beltoforion.de", "InstantLua")
    ,m_bEnableLineNumbers(true)
    ,m_bEnableSourceFolding(true)
    ,m_nFontSize(10)
    ,m_vSettingsProvider()
{}

//-------------------------------------------------------------------------------------------------
Settings::~Settings()
{}

//-------------------------------------------------------------------------------------------------
void Settings::setSourceFolding(bool bEnable)
{
    m_bEnableSourceFolding = bEnable;
}

//-------------------------------------------------------------------------------------------------
void Settings::setLineNumbers(bool bEnable)
{
    m_bEnableLineNumbers = bEnable;
}

//-------------------------------------------------------------------------------------------------
bool Settings::hasSourceFolding() const
{
    return m_bEnableSourceFolding;
}

//-------------------------------------------------------------------------------------------------
bool Settings::hasLineNumbers() const
{
    return m_bEnableLineNumbers;
}

//-------------------------------------------------------------------------------------------------
int Settings::getFontSize() const
{
    return m_nFontSize;
}

//-------------------------------------------------------------------------------------------------
void Settings::setFontSize(int nSize)
{
    m_nFontSize = nSize;
}

//-------------------------------------------------------------------------------------------------
int Settings::getTabIndent() const
{
    return m_nTabIndent;
}

//-------------------------------------------------------------------------------------------------
void Settings::setTabIndent(int nSize)
{
    m_nTabIndent = nSize;
}

//-------------------------------------------------------------------------------------------------
const QString& Settings::getProjectPath() const
{
    return m_sProjectPath;
}

//-------------------------------------------------------------------------------------------------
void Settings::setProjectPath(QString sPath)
{
    m_sProjectPath = sPath;
}

//-------------------------------------------------------------------------------------------------
void Settings::updateFromSettings()
{
    for (int i=0; i<m_vSettingsProvider.size(); ++i)
    {
        m_vSettingsProvider[i]->updateFromSettings();
    }
}

//-------------------------------------------------------------------------------------------------
void Settings::writeSettings()
{
    for (int i=0; i<m_vSettingsProvider.size(); ++i)
    {
        m_vSettingsProvider[i]->writeSettings(m_settings);
    }
}

//-------------------------------------------------------------------------------------------------
void Settings::readSettings()
{
    for (int i=0; i<m_vSettingsProvider.size(); ++i)
    {
        m_vSettingsProvider[i]->readSettings(m_settings);
    }
    updateFromSettings();
}

//-------------------------------------------------------------------------------------------------
void Settings::addProvider(ISettingsProvider *pSettingsProvider)
{
    m_vSettingsProvider.push_back(pSettingsProvider);
}

