#include "DlgNewFile.h"
#include "ui_DlgNewFile.h"

#include <QFileDialog>


//-------------------------------------------------------------------------------------------------
DlgNewFile::DlgNewFile(QWidget *parent, const Settings &settings)
    :QDialog(parent)
    ,ui(new Ui::DlgNewFile)
    ,m_settings(settings)
{
    ui->setupUi(this);

    Qt::WindowFlags flags;
    flags  = Qt::Window;
    flags |= Qt::WindowStaysOnTopHint;
    flags &=~Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->edProjectDir->setText(m_settings.getProjectPath());
//    setFocus();
    ui->edFileName->setFocus();
    on_edFileName_textChanged("");
}

//-------------------------------------------------------------------------------------------------
DlgNewFile::~DlgNewFile()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_btnProjectDir_clicked()
{
    QString sPath = QFileDialog::getExistingDirectory(this,
                                                      tr("Select an alternate project directory"),
                                                      m_settings.getProjectPath(),
                                                      QFileDialog::ShowDirsOnly);
    ui->edProjectDir->setText(sPath);
}

//-------------------------------------------------------------------------------------------------
QString DlgNewFile::getFileName() const
{
    return m_fi.absoluteFilePath();
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::refreshGUI(const QString &sFileName)
{
    QString sBaseName(sFileName);
    QString sExtension;
    int i = sFileName.indexOf('.');
    if (i!=-1)
    {
        sBaseName = sBaseName.left(i);
    }

    i = sFileName.lastIndexOf('.');
    if (i!=-1)
    {
        sExtension = sFileName.right(sFileName.length()-i);
    }

    if (sExtension.length()==0)
        sExtension = ".as";

    QString sFullPath;
    sFullPath = ui->edProjectDir->text();

    // Soll ein Unterverzeichnis angelegt werden, so heisst das wie der
    // Basisfilename
    if (ui->cbCreateDir->checkState())
    {
        sFullPath += "/" + sBaseName;
    }


    m_fi.setFile(QDir(sFullPath), sBaseName + sExtension);

    bool bAllowOk = false;

    // Check for empty file name
    if (sFileName.length()==0)
    {
        ui->lbHint->setText("Please input a filename");
        ui->lbIconHint->setPixmap(QPixmap(":/images/res/warning.ico"));
    }
    else if (m_fi.exists())
    {
        ui->lbHint->setText(QString("File already exists:\n%1").arg(m_fi.absoluteFilePath()));
        ui->lbIconHint->setPixmap(QPixmap(":/images/res/warning.ico"));
    }
    else
    {
        ui->lbHint->setText(m_fi.absoluteFilePath());
        ui->lbIconHint->setPixmap(QPixmap(":/images/res/ok.ico"));
        bAllowOk = true;
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(bAllowOk);
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_edFileName_textChanged(const QString &sFileName)
{
    refreshGUI(sFileName);
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_cbCreateDir_stateChanged(int arg1)
{
    refreshGUI(ui->edFileName->text());
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_buttonBox_accepted()
{
    accept();
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_buttonBox_rejected()
{
    reject();
}
