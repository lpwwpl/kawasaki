#ifndef QGRAPHICSITEMPOINTLIST_H
#define QGRAPHICSITEMPOINTLIST_H

#include <QGraphicsItem>
#include <QVector>


//-------------------------------------------------------------------------------------------------
class QGraphicsItemPointList : public QGraphicsItem
{
public:
    QGraphicsItemPointList(QGraphicsScene *pScene = NULL);
    void add(qreal x, qreal y);
    void clear();
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
    virtual QRectF boundingRect() const;

private:
    struct SPoint
    {
        SPoint(qreal a_x = 0, qreal a_y = 0)
            :x(a_x)
            ,y(a_y)
        {}

        qreal x;
        qreal y;
    };

    QVector<SPoint> m_vPoints;
    QRectF m_bounds;
};

#endif // QGRAPHICSITEMPOINTLIST_H
