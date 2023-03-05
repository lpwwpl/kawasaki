#include "QGradientPanel.h"
#include "ui_QGradientPanel.h"
#include <qstyleoption.h>
//-------------------------------------------------------------------------------------------------
#include <QPainter>
#include <QIcon>


//-------------------------------------------------------------------------------------------------
QGradientPanel::QGradientPanel(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::QGradientPanel)
{
    ui->setupUi(this);

    setColorScheme(csBLUE);
    ui->lbInfo1->setText("");
    ui->lbInfo2->setText("");
}

//-------------------------------------------------------------------------------------------------
QGradientPanel::~QGradientPanel()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void QGradientPanel::setCaption(const QString &sCaption)
{
    ui->lbCaption->setText(sCaption);
}

//-------------------------------------------------------------------------------------------------
void QGradientPanel::setInfo(int nLine, const QString &sInfo)
{
    if (nLine==0)
    {
        ui->lbInfo1->setText(sInfo);
    }
    else
    {
        ui->lbInfo2->setText(sInfo);
    }
}

//-------------------------------------------------------------------------------------------------
void QGradientPanel::setColorScheme(EColorScheme eScheme)
{
    switch(eScheme)
    {
    case csBLUE:
        setStyleSheet(QString::fromUtf8("color: white;\n"
                                        "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #eef, stop: 0.49 #78b, stop: 0.5 #66b, stop: 1 #8ac);\n"
                                        "border-width: 1px;\n"
                                        "border-color: #000;\n"
                                        "border-style: solid;\n"
                                        "border-radius: 4;\n\n"));
        break;

    case csRED:
        setStyleSheet(QString::fromUtf8("color: white;\n"
                                        "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d88, stop: 0.1 #fee, stop: 0.49 #b87, stop: 0.5 #b66, stop: 1 #ca8);\n"
                                        "border-width: 1px;\n"
                                        "border-color: #000;\n"
                                        "border-style: solid;\n"
                                        "border-radius: 4;\n\n"));
        break;
    }
}

//-------------------------------------------------------------------------------------------------
void QGradientPanel::setIcon(const QPixmap &pm)
{
    ui->lbImage->setPixmap(pm);
}

//-------------------------------------------------------------------------------------------------
/** \brief paintEvent muss implementiert werden, damit stylesheets funktionieren.

    http://www.qtcentre.org/threads/37976-Q_OBJECT-and-CSS-background-image
*/
void QGradientPanel::paintEvent(QPaintEvent *pe)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}
