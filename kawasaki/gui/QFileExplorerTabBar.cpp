#include "QFileExplorerTabBar.h"
#include <QMouseEvent>


//-------------------------------------------------------------------------------------------------
QFileExplorerTabBar::QFileExplorerTabBar()
{}

//-------------------------------------------------------------------------------------------------
QFileExplorerTabBar::~QFileExplorerTabBar()
{}

//-------------------------------------------------------------------------------------------------
void QFileExplorerTabBar::mouseReleaseEvent(QMouseEvent *pEvent)
{
    QTabBar::mouseReleaseEvent(pEvent);

    if (pEvent->button()==Qt::MidButton)
    {
        emit tabCloseRequested(this->tabAt(pEvent->pos()));
    }
}
