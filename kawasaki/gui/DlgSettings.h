#ifndef DLGSETTINGS_H
#define DLGSETTINGS_H

#include <QDialog>

//--- Luanda implementation -----------------------------------------------------------------------
#include "ISettingsProvider.h"


namespace Ui {
    class DlgSettings;
}

//-------------------------------------------------------------------------------------------------
class DlgSettings : public QDialog,
                    public ISettingsProvider
{
    Q_OBJECT

public:
    explicit DlgSettings(QWidget *parent = 0);
    ~DlgSettings();

    // ISettingsProvider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

private:
    Ui::DlgSettings *ui;

private slots:
    void on_cbLineNumbers_clicked(bool checked);
    void on_cbFolding_clicked(bool checked);
    void on_sbFontSize_valueChanged(int nSize);
    void on_sbTabIndent_valueChanged(int nIndent);
    void on_btnSelectProjectDir_clicked();
};

#endif // DLGSETTINGS_H
