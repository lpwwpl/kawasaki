#include "QGraphicsItemPointList.h"
#include <QPainter>
#include <QGraphicsScene>


//-------------------------------------------------------------------------------------------------
QGraphicsItemPointList::QGraphicsItemPointList(QGraphicsScene *pScene)
    :QGraphicsItem()
    ,m_vPoints()
    ,m_bounds()
{
    if (pScene!=NULL)
        pScene->addItem(this);
}

//-------------------------------------------------------------------------------------------------
void QGraphicsItemPointList::add(qreal x, qreal y)
{
    if (!m_bounds.contains(x, y))
    {
        prepareGeometryChange();
        m_bounds = m_bounds.united(QRect(x, y, 1, 1));
    }

    m_vPoints.push_back(SPoint(x,y));
}

//-------------------------------------------------------------------------------------------------
void QGraphicsItemPointList::clear()
{
    m_bounds.setRect(0, 0, 0, 0);
    m_vPoints.clear();
}

//-------------------------------------------------------------------------------------------------
QRectF QGraphicsItemPointList::boundingRect() const
{
    return m_bounds;
}

//-------------------------------------------------------------------------------------------------
void QGraphicsItemPointList::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
{
    for (int i=0; i<m_vPoints.size(); ++i)
    {
        const SPoint &s = m_vPoints[i];
        //painter->drawPoint(s.x, s.y);
        painter->drawLine(s.x-1, s.y,   s.x+1, s.y);
        painter->drawLine(s.x,   s.y-1, s.x,   s.y+1);
    }
}

