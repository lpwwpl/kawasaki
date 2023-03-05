#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QtGui/QTableView>
#include <QtGui/QTreeView>

class DataTreeView;

class TableView : public QTableView
{
    Q_OBJECT

public:
    TableView(QWidget *parent = 0);
    ~TableView();
    static TableView* _Instance;

    virtual void setModel( QAbstractItemModel * model );
    //virtual void wheelEvent(QWheelEvent *event);

protected:
    virtual void resizeEvent(QResizeEvent *event);
    
    virtual void paintEvent(QPaintEvent *event);

    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    void init();
public:
    void updateFrozenTableGeometry();

public:
    DataTreeView* _dataTree;
};

#endif // MYTABLEVIEW_H
