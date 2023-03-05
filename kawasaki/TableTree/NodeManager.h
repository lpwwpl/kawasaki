#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include <QMap>

#include "DataNode.h"

struct TNodeData
{
    QString _serialNo;
    DataNode::Type _type;
    float _codeNo;
    QString _name;

    QDate _planBeginDate;
    QDate _planEndDate;
    int _planDays;

    QDate _realBeginDate;
    QDate _realEndDate;
    int _realDays;

    int _totalDays;
    QString _mask;

    TNodeData()
    {
        _serialNo = "";
        _type = DataNode::Unknown;
        _codeNo = 0.0;
        _name = "";
        _planBeginDate = QDate();
        _planEndDate = QDate();
        _planDays = 0;

        _realBeginDate = QDate();
        _realEndDate = QDate();
        _realDays = 0;

        _totalDays = 0;
        _mask = "";
    }

    void clear()
    {
        _serialNo = "";
        _type = DataNode::Unknown;
        _codeNo = 0.0;
        _name = "";
        _planBeginDate = QDate();
        _planEndDate = QDate();
        _planDays = 0;

        _realBeginDate = QDate();
        _realEndDate = QDate();
        _realDays = 0;

        _totalDays = 0;
        _mask = "";
    }
};
class NodeManager
{
public:
    static NodeManager* getInstance();
    static void destroyInstance();

    //���ʼ��
    int init();
    DataNode* addNode(const TNodeData& data, DataNode* parent = NULL);
    DataNode* RootNode() { return _rootNode; }

    //���ڵ��˳���ÿһ���ڵ㸳��һ��˳���
    void sortData(DataNode* parent = NULL);

    const QMap<int, DataNode*>& sortMap() { return _sortMap; }

    //��ȡ�ڵ������е�����ڵ�
    void allChildNode(DataNode* parent, QList<DataNode*>& childList);

    //��ȡ�ڵ����еĸ��ڵ�
    void allParentNode(DataNode* child, QList<DataNode*>& parentList);

	//��ȡnode��Ӧ��˳���
	int serialNoOfNode(DataNode* node);

    //��ȡ��ǰnode�Ĳ㼶���������Ҹ��ڵ�Ĳ���
    int nodeStep(DataNode* node);
private:
    bool isNodeInModel(DataNode* const node);

private:
    NodeManager();
    ~NodeManager();
    static NodeManager* _instance;

    DataNode* _rootNode;

    //keyΪnode�����,valueΪnode
    QMap<int, DataNode*> _sortMap;
    //keyΪnode��valueΪnode�����
    QMap<DataNode*, int> _serialMap;

    //���浱ǰ��չ��node����Ŀ
    int _expandedNodeNum;
};

#endif 
