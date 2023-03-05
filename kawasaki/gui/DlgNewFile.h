#ifndef DLGNEWFILE_H
#define DLGNEWFILE_H

#include <QDialog>
#include <QFileInfo>
#include "Settings.h"


namespace Ui {
class DlgNewFile;
}

class DlgNewFile : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgNewFile(QWidget *parent, const Settings &settings);
    ~DlgNewFile();
    QString getFileName() const;

private slots:
    void on_btnProjectDir_clicked();
    void on_edFileName_textChanged(const QString &arg1);
    void on_cbCreateDir_stateChanged(int arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:

    void refreshGUI(const QString &sFileName);

    Ui::DlgNewFile *ui;
    const Settings &m_settings;
    QString m_sFullName;
    QFileInfo m_fi;
};

#endif // DLGNEWFILE_H
