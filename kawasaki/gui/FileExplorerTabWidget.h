#ifndef FILEEXPLORERTABWIDGET_H
#define FILEEXPLORERTABWIDGET_H

//--- Qt lib includes -----------------------------------------------------------------------------
#include <QObject>
#include <QTabWidget>
#include <QMenu>

//-------------------------------------------------------------------------------------------------
#include "FwdDecl.h"
#include "QFileExplorerTabBar.h"


//-------------------------------------------------------------------------------------------------
class FileExplorerTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    FileExplorerTabWidget(QWidget *pParent = NULL);

    void contextMenuEvent(QContextMenuEvent* e);

    QAction *m_pActionClose;
    QAction *m_pActionCloseOther;
    QMenu* m_pTabMenu;
    QFileExplorerTabBar *m_pTabBar;

private slots:
    void closeCurrentTab();
    void closeTab(int idx);
    void closeOther();
};

#endif // FILEEXPLORERTABWIDGET_H
