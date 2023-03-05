#ifndef WNDCANVAS_H
#define WNDCANVAS_H

#include <QGraphicsView>
#include <QGraphicsItemPointList.h>

namespace Ui {
class WndCanvas;
}


//-------------------------------------------------------------------------------------------------
class WndCanvas : public QGraphicsView
{
    Q_OBJECT
    
public:
    explicit WndCanvas(int width, int height, QString title);
    ~WndCanvas();
    
    void setSceneSize(int w, int h);
    void moveTo(double x, double y);
    void drawTo(double x, double y);
    void drawEllipse(double x1, double y1, double x2, double y2);
    void drawCircle(double x, double y, double r);
    void drawPoint(double x, double y);
    virtual void wheelEvent(QWheelEvent* event);

private:
    Ui::WndCanvas *ui;
    QGraphicsScene m_scene;
    QGraphicsItemPointList *m_pPointList;

    QPoint m_pos;
};

#endif // WNDCANVAS_H
