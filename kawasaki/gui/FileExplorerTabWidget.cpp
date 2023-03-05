#include "FileExplorerTabWidget.h"

//--- Qt lib includes -----------------------------------------------------------------------------
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QDebug>


//-------------------------------------------------------------------------------------------------
FileExplorerTabWidget::FileExplorerTabWidget(QWidget *pParent)
    :QTabWidget(pParent)
    ,m_pActionClose(new QAction(tr("Close"), this))
    ,m_pActionCloseOther(new QAction(tr("Close All But This"), this))
    ,m_pTabMenu(NULL)
    ,m_pTabBar(new QFileExplorerTabBar())
{
    m_pActionClose->setIcon(QIcon(":/images/res/tab-close-3.ico"));
    m_pActionCloseOther->setIcon(QIcon(":/images/res/tab-close-other.ico"));

    setTabBar(m_pTabBar);

    connect(m_pActionClose, SIGNAL(triggered()), this, SLOT(closeCurrentTab()));
    connect(m_pActionCloseOther, SIGNAL(triggered()), this, SLOT(closeOther()));

    m_pTabMenu = new QMenu(this);
    m_pTabMenu->addAction(m_pActionClose);
    m_pTabMenu->addAction(m_pActionCloseOther);
}

//-------------------------------------------------------------------------------------------------
void FileExplorerTabWidget::contextMenuEvent(QContextMenuEvent* /*e*/)
{
    m_pTabMenu->exec( QCursor::pos() );
}

//-------------------------------------------------------------------------------------------------
/***/
void FileExplorerTabWidget::closeCurrentTab()
{
    closeTab(currentIndex());
}

//-------------------------------------------------------------------------------------------------
/** \brief Schließen aller Tabsheets bis auf den derzeit aktiven. */
void FileExplorerTabWidget::closeOther()
{
    int idx = currentIndex();
    if (idx==-1)
        return;

    for (int i=count(); i>=0; --i)
    {
        if (i!=idx)
        {
            closeTab(i);
        }
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Schliessen des Tabsheets mit einem bestimmten index.
    \param idx Index des zu schliessenden Tabsheets

  Sollte der angegebenen index kleiner als 0 oder größer als die Anzahl der Tabshetts sein passiert
  nichts.
*/
void FileExplorerTabWidget::closeTab(int idx)
{
    if (idx<0 || idx>=count())
        return;

    QWidget *pPage = widget(idx);
    removeTab(idx);
    delete pPage;
}




