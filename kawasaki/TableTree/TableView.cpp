#include <QScrollBar>
#include <QHeaderView>
#include <QEvent>
#include <QWheelEvent>

#include "TableView.h"
#include "DataTreeView.h"
#include "HHeaderView.h"

TableView* TableView::_Instance = NULL;

TableView::TableView(QWidget *parent) : QTableView(parent)
{
    this->setWindowIcon(QIcon("./Resources/logo.ico"));

    _dataTree = new DataTreeView(this);
    _Instance = this;

    //_dataTree->installEventFilter(this);
    connect(_dataTree->verticalScrollBar(), SIGNAL(valueChanged(int)), this->verticalScrollBar(), SLOT(setValue(int)));
    //connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)), _dataTree->verticalScrollBar(), SLOT(setValue(int)));

    //connect(_dataTree->horizontalScrollBar(), SIGNAL(valueChanged(int)), this->horizontalScrollBar(), SLOT(setValue(int)));
    connect(this->horizontalScrollBar(), SIGNAL(valueChanged(int)), _dataTree->horizontalScrollBar(), SLOT(setValue(int)));

    this->installEventFilter(this);
}

TableView::~TableView()
{

}


void TableView::setModel( QAbstractItemModel * model )
{
    //QTableView::setModel(model);
    _dataTree->setModel(model);

    init();
}

void TableView::init()
{
    //_dataTree->setFocusPolicy(Qt::NoFocus);

    //viewport()->stackUnder(_dataTree);

    //_dataTree->setSelectionModel(selectionModel());
    //for(int col = 0; col < model()->columnCount(); col++)
    {
       // this->setColumnHidden(col, true);
       // _dataTree->setColumnWidth(col, this->columnWidth(col) );
    }

    _dataTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //_dataTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    _dataTree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    _dataTree->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    //this->verticalHeader()->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);

    updateFrozenTableGeometry();
}

void TableView::resizeEvent(QResizeEvent * event)
{
    QTableView::resizeEvent(event);    
    updateFrozenTableGeometry();
}

void TableView::paintEvent(QPaintEvent *event)
{//table��paint�������ܽ���Ĭ�ϴ���Ҫ���ڽ���resize��ʱ������ҵ� ���������������������ʱ����ʱ������ͷʱҲ��ҵ�
    return; 
}

void TableView::updateFrozenTableGeometry()
{
    int vw = verticalHeader()->width();
    int fw = frameWidth();
    int ww = viewport()->width();
    int hh = viewport()->height();
    int vh = horizontalHeader()->height();
    _dataTree->setGeometry(verticalHeader()->width() + frameWidth(),
        frameWidth(), viewport()->width(),
        viewport()->height() + horizontalHeader()->height());
}

/*
void TableView::wheelEvent(QWheelEvent *event)
{
    if (event->delta() < 0)
    {
        int value = this->verticalScrollBar()->value();
        this->verticalScrollBar()->setValue(value + 1 * 30);
    }
    else
    {
        int value = this->verticalScrollBar()->value();
        this->verticalScrollBar()->setValue(value - 1 * 30);
    }
}
*/

bool TableView::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this)
    {
        QEvent::Type type = event->type();
        if(type == QEvent::Show)
        {
            HHeaderView::_Instance->resizeLastSection(false);
        }
        else if (type == QEvent::Hide)
        {
            HHeaderView::_Instance->resizeLastSection(true);
        }
    }

    return false;
}