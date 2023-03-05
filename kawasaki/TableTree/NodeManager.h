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

    //类初始化
    int init();
    DataNode* addNode(const TNodeData& data, DataNode* parent = NULL);
    DataNode* RootNode() { return _rootNode; }

    //按节点的顺序给每一个节点赋予一个顺序号
    void sortData(DataNode* parent = NULL);

    const QMap<int, DataNode*>& sortMap() { return _sortMap; }

    //获取节点下所有的子孙节点
    void allChildNode(DataNode* parent, QList<DataNode*>& childList);

    //获取节点所有的父节点
    void allParentNode(DataNode* child, QList<DataNode*>& parentList);

	//获取node对应的顺序号
	int serialNoOfNode(DataNode* node);

    //获取当前node的层级，即网上找根节点的层数
    int nodeStep(DataNode* node);
private:
    bool isNodeInModel(DataNode* const node);

private:
    NodeManager();
    ~NodeManager();
    static NodeManager* _instance;

    DataNode* _rootNode;

    //key为node的序号,value为node
    QMap<int, DataNode*> _sortMap;
    //key为node，value为node的序号
    QMap<DataNode*, int> _serialMap;

    //保存当前扩展的node的数目
    int _expandedNodeNum;
};

#endif 
