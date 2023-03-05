#ifndef QFILEEXPLORERTABBAR_H
#define QFILEEXPLORERTABBAR_H

#include <QTabBar>


//-------------------------------------------------------------------------------------------------
class QFileExplorerTabBar : public QTabBar
{
public:
    QFileExplorerTabBar();
    virtual ~QFileExplorerTabBar();

    // von QWidget
    virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // QFILEEXPLORERTABBAR_H
