#include "DlgAbout.h"
#include "ui_DlgAbout.h"

#include <QApplication>

//-------------------------------------------------------------------------------------------------
DlgAbout::DlgAbout(QWidget *parent)
    :QDialog(parent)
    ,ui(new Ui::DlgAbout)
{

    ui->setupUi(this);

    Qt::WindowFlags flags;
    flags  = Qt::Tool;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);

    QString sHtml = ui->textEdit->document()->toHtml();
    QString sVersion = qApp->applicationVersion();
    sHtml.replace("$APP_VERSION$", qApp->applicationVersion());
    sHtml.replace("$BUILD_DATE$", __DATE__);
    ui->textEdit->setHtml(sHtml);
}

//-------------------------------------------------------------------------------------------------
DlgAbout::~DlgAbout()
{
    delete ui;
}
