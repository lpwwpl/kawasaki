#include <QtGui/QApplication>
#include <QTextCodec>
#include <QSortFilterProxyModel>
#include <QObject>

#include "TableView.h"
#include "HHeaderModel.h"
#include "HHeaderView.h"
#include "NodeManager.h"
#include "DataModel.h"

#include "VHeaderModel.h"
#include "VHeaderView.h"
#include "DataTreeView.h"

void InitHHeaderModel(HHeaderModel* horizontalHeaderModel)
{
    horizontalHeaderModel->setItem(0,0, QObject::tr("�����ֽ�ṹ"));
    horizontalHeaderModel->setItem(0,4, QObject::tr("�ƻ�����"));
    horizontalHeaderModel->setItem(0,7, QObject::tr("ʵ�ʽ���"));
    horizontalHeaderModel->setItem(0,10, QObject::tr("����"));
    horizontalHeaderModel->setItem(0,11, QObject::tr("��ע"));

    horizontalHeaderModel->setItem(1,0, QObject::tr("���"));
    horizontalHeaderModel->setItem(1,1, QObject::tr("����"));
    horizontalHeaderModel->setItem(1,2, QObject::tr("��������"));
    horizontalHeaderModel->setItem(1,3, QObject::tr("��������"));
    horizontalHeaderModel->setItem(1,4, QObject::tr("��ʼʱ��"));
    horizontalHeaderModel->setItem(1,5, QObject::tr("����ʱ��"));
    horizontalHeaderModel->setItem(1,6, QObject::tr("����"));
    horizontalHeaderModel->setItem(1,7, QObject::tr("��ʼʱ��"));
    horizontalHeaderModel->setItem(1,8, QObject::tr("����ʱ��"));
    horizontalHeaderModel->setItem(1,9, QObject::tr("����"));
   
    horizontalHeaderModel->setSpan(0,0,1,4);
    horizontalHeaderModel->setSpan(0,4,1,3);
    horizontalHeaderModel->setSpan(0,7,1,3);

    horizontalHeaderModel->setSpan(0,10,2,1);
    horizontalHeaderModel->setSpan(0,11,2,1); //��֧�ֿ�Խ���ж��е����
}

void InitDataModel()
{
    TNodeData tData;
    tData._serialNo = QObject::tr("��λ����");
    tData._type = DataNode::Root;

    DataNode* rootNode = NodeManager::getInstance()->addNode(tData);

    tData.clear();

    int max = 5;
    for (int i = 0; i < max; i++)
    {
        tData._serialNo = QObject::tr("1���ӽڵ�A") + "_" + QString::number(i);
        tData._type = DataNode::Summary;
        tData._codeNo = 1;
        tData._name = QObject::tr("����ʩ��");
        tData._planBeginDate = QDate::fromString("2012-11-08", "yyyy-MM-dd");
        tData._planEndDate = QDate::fromString("2012-12-08", "yyyy-MM-dd");
        tData._planDays = 30;
        tData._realBeginDate = QDate::fromString("2012-11-08", "yyyy-MM-dd");
        tData._realEndDate = QDate::fromString("2012-12-08", "yyyy-MM-dd");
        tData._realDays = 30;
        tData._totalDays = 30;
        tData._mask = QObject::tr("��ʱ�깤");

        DataNode* nodeA = NodeManager::getInstance()->addNode(tData, rootNode);
        tData._serialNo = QObject::tr("A1") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.1;
        tData._name = QObject::tr("��������");

        DataNode* nodeA1 = NodeManager::getInstance()->addNode(tData, nodeA);

        tData._serialNo = QObject::tr("A2") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.2;
        tData._name = QObject::tr("һ׮��̨����");

        DataNode* nodeA2 = NodeManager::getInstance()->addNode(tData, nodeA);

        tData._serialNo = QObject::tr("A3") + "_" + QString::number(i);
        tData._type = DataNode::Summary;
        tData._codeNo = 1.3;
        tData._name = QObject::tr("��׮��̨����");

        DataNode* nodeA3 = NodeManager::getInstance()->addNode(tData, nodeA);

        tData._serialNo = QObject::tr("A31") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.31;
        tData._name = QObject::tr("����1");

        DataNode* nodeA31 = NodeManager::getInstance()->addNode(tData, nodeA3);

        tData._serialNo = QObject::tr("A32") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.32;
        tData._name = QObject::tr("����2");

        DataNode* nodeA32 = NodeManager::getInstance()->addNode(tData, nodeA3);

        tData._serialNo = QObject::tr("A4") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.4;
        tData._name = QObject::tr("��׮��̨����");

        DataNode* nodeA4 = NodeManager::getInstance()->addNode(tData, nodeA);

         tData._serialNo = QObject::tr("A5") + "_" + QString::number(i);
        tData._type = DataNode::Task;
        tData._codeNo = 1.4;
        tData._name = QObject::tr("���彽��");

        DataNode* nodeA5 = NodeManager::getInstance()->addNode(tData, nodeA);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));

    QApplication::addLibraryPath("./plugins");

    HHeaderView* headerView = new HHeaderView(Qt::Horizontal);
    HHeaderModel* horizontalHeaderModel = new HHeaderModel();
    InitHHeaderModel(horizontalHeaderModel);
    headerView->setModel(horizontalHeaderModel);

    headerView->setCheckedEnable(1, 0, true);

    headerView->setCheckedEnable(1, 2, true);

    headerView->setSortedEnable(1, 4);
    headerView->setSortedEnable(1, 5);
    headerView->setSortedEnable(1, 7);
    headerView->setSortedEnable(1,8);

    headerView->setCustomMenuEnbale(1,1);
    headerView->setCustomMenuEnbale(1,2);
    headerView->setCustomMenuEnbale(1,3);
    headerView->setCustomMenuEnbale(1,10);
    headerView->setCustomMenuEnbale(1,11);

    NodeManager::getInstance()->init();
    InitDataModel();
    NodeManager::getInstance()->sortData();

    DataModel* dataModel = new DataModel();
    dataModel->setRootNode(NodeManager::getInstance()->RootNode());
    

    TableView w;

    /*QSortFilterProxyModel* sortModel = new QSortFilterProxyModel();
    sortModel->setSourceModel(dataModel);
    w.setModel(sortModel);*/

    w.setModel(dataModel);
    w.setHorizontalHeader(headerView);
    w._dataTree->setHeader(headerView);
    w._dataTree->expandAll();

    

    VHeaderView* vHeaderView = new VHeaderView(Qt::Vertical);
    VHeaderModel* vHeaderModel = new VHeaderModel();

    vHeaderView->setModel(vHeaderModel);
    w.setVerticalHeader(vHeaderView);
    /*QTreeView w;
    w.setModel(dataModel);
    w.setHeader(headerView);
    w.expandAll();*/

    //w.resize(1200,800);
    w.showMaximized();

    w.setColumnWidth(0, 180);
    w.setColumnWidth(1, 80);
    w.setColumnWidth(2, 80);
    w.setColumnWidth(3, 120);
    w.setColumnWidth(4, 120);
    w.setColumnWidth(5, 120);
    w.setColumnWidth(6, 60);
    w.setColumnWidth(7, 120);
    w.setColumnWidth(8, 120);
    w.setColumnWidth(9, 60);
    w.setColumnWidth(10, 270);
    w.setColumnWidth(11, 60);
    w.show();
    return a.exec();
}
