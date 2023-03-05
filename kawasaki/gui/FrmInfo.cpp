#include "FrmInfo.h"
#include "ui_FrmInfo.h"

//--- Qt lib includes -----------------------------------------------------------------------------
#include <QDesktopWidget>


//-------------------------------------------------------------------------------------------------
FrmInfo::FrmInfo(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::FrmInfo)
{
    ui->setupUi(this);
    hide();
}

//-------------------------------------------------------------------------------------------------
FrmInfo::~FrmInfo()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmInfo::show(int nCloseAfterMillis)
{
    show();
    QTimer::singleShot(nCloseAfterMillis, this, SLOT(close()));
}

//-------------------------------------------------------------------------------------------------
void FrmInfo::setTitle(const QString &msg)
{
    ui->lbTitle->setText(msg);
}

//-------------------------------------------------------------------------------------------------
void FrmInfo::setSubTitle(const QString &msg)
{
    ui->lbSubTitle->setText(msg);
}

//-------------------------------------------------------------------------------------------------
void FrmInfo::center()
{
    move(parentWidget()->width()/2 - width()/2,
         parentWidget()->height()/2 - height()/2);

}

//-------------------------------------------------------------------------------------------------
void FrmInfo::showEvent(QShowEvent *event)
{
    center();
}

