#ifndef FRMINFO_H
#define FRMINFO_H

#include <QWidget>
#include <QTimer>


namespace Ui {
    class FrmInfo;
}

class FrmInfo : public QWidget
{
    Q_OBJECT

public:
    explicit FrmInfo(QWidget *parent = 0);
    ~FrmInfo();

    void setTitle(const QString &msg);
    void setSubTitle(const QString &msg);
    void center();

    using QWidget::show;
    void show(int nCloseAfterMillis);

    // QWidget implementation
    virtual void showEvent (QShowEvent *event);

private:
    Ui::FrmInfo *ui;
};

#endif // FRMINFO_H
