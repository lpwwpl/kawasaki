#ifndef QGRADIENTPANEL_H
#define QGRADIENTPANEL_H

//-------------------------------------------------------------------------------------------------
#include <QWidget>


namespace Ui {
class QGradientPanel;
}

//-------------------------------------------------------------------------------------------------
class QGradientPanel : public QWidget
{
    Q_OBJECT
    
public:

    //---------------------------------------------------------------------------------------------
    enum EColorScheme
    {
        csBLUE = 0,
        csRED  = 1
    };

    explicit QGradientPanel(QWidget *parent = 0);
    ~QGradientPanel();

    void setCaption(const QString &sCaption);
    void setInfo(int nLine, const QString &sInfo);
    void setColorScheme(EColorScheme scheme);
    void setIcon(const QPixmap &pm);

protected:
    void paintEvent(QPaintEvent *pe);

private:
    Ui::QGradientPanel *ui;
};

#endif // QGRADIENTPANEL_H
