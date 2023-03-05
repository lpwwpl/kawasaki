#include "DlgSettings.h"
#include "ui_DlgSettings.h"

#include "Settings.h"
#include <QFileDialog>


//-------------------------------------------------------------------------------------------------
DlgSettings::DlgSettings(QWidget *parent)
    :QDialog(parent)
    ,ISettingsProvider()
    ,ui(new Ui::DlgSettings)
{
    ui->setupUi(this);
    setSizeGripEnabled(false);
}

//-------------------------------------------------------------------------------------------------
DlgSettings::~DlgSettings()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::writeSettings(QSettings &qs)
{
    qs.beginGroup("GlobalSettings");

    const Settings &settings = Settings::Instance();
    qs.setValue(keyShowLineNumbers, settings.hasLineNumbers() ? Qt::Checked : Qt::Unchecked);
    qs.setValue(keyEnableSourceFolding, settings.hasSourceFolding() ? Qt::Checked : Qt::Unchecked);
    qs.setValue(keyFontSize, settings.getFontSize());
    qs.setValue(keyTabIndent, settings.getTabIndent());
    qs.setValue(keyProjectPath, settings.getProjectPath());
    qs.endGroup();
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::readSettings(QSettings &qs)
{
    qs.beginGroup("GlobalSettings");

    Settings &settings = Settings::Instance();
    settings.setLineNumbers(qs.value(keyEnableSourceFolding, true).toInt()==Qt::Checked);
    settings.setSourceFolding(qs.value(keyShowLineNumbers, true).toInt()==Qt::Checked);
    settings.setFontSize(qs.value(keyFontSize, 10).toInt());
    settings.setTabIndent(qs.value(keyTabIndent, 2).toInt());

    // Defaultpfad ist Projektverzeichnis im exe-Directory
    QString sDefaultPath = QCoreApplication::applicationDirPath() + tr("/projects");
    settings.setProjectPath(qs.value(keyProjectPath, sDefaultPath).toString());
    qs.endGroup();
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren des Settings Dialoges auf basis des Settings Objektes.
*/
void DlgSettings::updateFromSettings()
{
    Settings &settings = Settings::Instance();
    ui->cbLineNumbers->setCheckState(settings.hasLineNumbers() ? Qt::Checked : Qt::Unchecked);
    ui->cbFolding->setCheckState(settings.hasSourceFolding() ? Qt::Checked : Qt::Unchecked);
    ui->sbFontSize->setValue(settings.getFontSize());
    ui->sbTabIndent->setValue(settings.getTabIndent());
    ui->edProjectDir->setText(settings.getProjectPath());
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::on_cbFolding_clicked(bool checked)
{
    Settings &settings = Settings::Instance();
    settings.setSourceFolding(checked ? Qt::Checked : Qt::Unchecked);
    settings.updateFromSettings();
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::on_cbLineNumbers_clicked(bool checked)
{
    Settings &settings = Settings::Instance();
    settings.setLineNumbers(checked ? Qt::Checked : Qt::Unchecked);
    settings.updateFromSettings();
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::on_sbFontSize_valueChanged(int nSize)
{
    Settings &settings = Settings::Instance();
    settings.setFontSize(nSize);
    settings.updateFromSettings();
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::on_sbTabIndent_valueChanged(int nIndent)
{
    Settings &settings = Settings::Instance();
    settings.setTabIndent(nIndent);
    settings.updateFromSettings();
}

//-------------------------------------------------------------------------------------------------
void DlgSettings::on_btnSelectProjectDir_clicked()
{
    Settings &settings = Settings::Instance();
    QString sPath = QFileDialog::getExistingDirectory(this,
                                                      tr("Select the project directory"),
                                                      settings.getProjectPath(),
                                                      QFileDialog::ShowDirsOnly);

    settings.setProjectPath(sPath);
    settings.updateFromSettings();
}
