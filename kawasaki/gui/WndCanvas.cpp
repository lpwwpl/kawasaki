#include "WndCanvas.h"
#include "ui_wndcanvas.h"

#include <QGraphicsEllipseItem>
#include <QWheelEvent>
#include <QDebug>

#include <QGraphicsItemPointList.h>

//-------------------------------------------------------------------------------------------------
WndCanvas::WndCanvas(int width, int height, QString title)
    :QGraphicsView((QWidget*)0)
    ,ui(new Ui::WndCanvas)
    ,m_pos(0,0)
{
    ui->setupUi(this);

    m_pPointList = new QGraphicsItemPointList(&m_scene);

    setWindowTitle(title);
    setScene(&m_scene);
    setBackgroundBrush(QBrush(Qt::white));
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);

    setMinimumSize(400, 400);
    setSceneSize(width, height);
}

//-------------------------------------------------------------------------------------------------
WndCanvas::~WndCanvas()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void WndCanvas::setSceneSize(int w, int h)
{
    resize(w + 2*geometry().x() + 5, h + geometry().y() + 5);
    m_scene.setSceneRect(0, 0, w, h);
}

//-----------------------------------------------------------------------------
void WndCanvas::moveTo(double x, double y)
{
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::drawTo(double x, double y)
{
    m_scene.addLine(m_pos.x(), m_pos.y(), x, y);
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::drawPoint(double x, double y)
{
    m_pPointList->add((qreal)x, (qreal)y);
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::drawEllipse(double x1, double y1, double x2, double y2)
{
    m_scene.addEllipse(x1, y1, x2-x1, y2-y1);
    m_pos = QPoint(x2, y2);
}

//-----------------------------------------------------------------------------
void WndCanvas::drawCircle(double x, double y, double r)
{
    m_scene.addEllipse(x-r, y-r, 2*r, 2*r);
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::wheelEvent(QWheelEvent* event)
{
    QTransform t = transform();
    double fx = (event->delta() > 0) ? 1.1 : 1.0/1.1,
           fy = fx;

    scale(fx, fy);
}
