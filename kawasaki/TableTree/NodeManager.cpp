#include "NodeManager.h"

NodeManager* NodeManager::_instance = NULL;


NodeManager::NodeManager()
{
    _rootNode = NULL;
}

NodeManager::~NodeManager()
{
}

NodeManager* NodeManager::getInstance()
{
    if (NULL == _instance)
    {
        _instance = new NodeManager();
    }

    return _instance;
}

void NodeManager::destroyInstance()
{
    if (NULL != _instance)
    {
        delete _instance;
        _instance = NULL;
    }
}

int NodeManager::init()
{
    _rootNode = new DataNode();
    _rootNode->setType(DataNode::Root);

    return 0;
}

DataNode* NodeManager::addNode(const TNodeData& data, DataNode* parent)
{
    if (NULL == parent)
    {//加到rootnode下
        DataNode* node = new DataNode();
        node->setParent(_rootNode);

        node->setType(data._type);
        node->setSerialNo(data._serialNo);
        node->setCodeNo(data._codeNo);
        node->setName(data._name);
        node->setPlanBeginDate(data._planBeginDate);
        node->setPlanEndDate(data._planEndDate);
        node->setPlanDays(data._planDays);
        node->setRealBeginDate(data._realBeginDate);
        node->setRealEndDate(data._planEndDate);
        node->setRealDays(data._realDays);
        node->setTotalDays(data._totalDays);
        node->setMask(data._mask);

        return node;
    }

    //判断parent是否当前rootnode底下的一个子节点
    if (!isNodeInModel(parent))
    {
        return NULL;
    }

    DataNode* node = new DataNode();
    node->setParent(parent);

    node->setType(data._type);
    node->setSerialNo(data._serialNo);
    node->setCodeNo(data._codeNo);
    node->setName(data._name);
    node->setPlanBeginDate(data._planBeginDate);
    node->setPlanEndDate(data._planEndDate);
    node->setPlanDays(data._planDays);
    node->setRealBeginDate(data._realBeginDate);
    node->setRealEndDate(data._planEndDate);
    node->setRealDays(data._realDays);
    node->setTotalDays(data._totalDays);
    node->setMask(data._mask);

    return node;
}

bool NodeManager::isNodeInModel(DataNode* const node)
{
    if (NULL == node) 
        return NULL;

    bool flag = false;
    DataNode* parent = node->parent();
    while (NULL != parent)
    {
        if (_rootNode == parent)
        {
            flag = true;

            break;
        }

        parent = parent->parent();
    }

    return flag;
}

void NodeManager::sortData(DataNode* parent)
{
    static int SERIALNO = 0;

    if (NULL == parent)
    {
        SERIALNO = 0;
        parent = _rootNode;
    }
 
    QList<DataNode*> child = parent->children();
    for (int i = 0; i < child.size(); ++i)
    {
        int curNum = SERIALNO++;
        DataNode* node = child.at(i);
        _sortMap[curNum] = node;

        //再保存多一份数据,方便查找
        _serialMap[node] = curNum;

        if (!node->children().isEmpty())
        {
            sortData(node);
        }  
    }
}

void NodeManager::allChildNode(DataNode* parent, QList<DataNode*>& childList)
{
    if (NULL == parent)
    {
        parent = _rootNode;
    }

    QList<DataNode*> child = parent->children();
    for (int i = 0; i < child.size(); ++i)
    {
        DataNode* node = child.at(i);
        if (!node->children().isEmpty())
        {
            allChildNode(node, childList);
        }

        childList.push_back(node);
    }
}

int NodeManager::serialNoOfNode(DataNode* node)
{
    QMap<DataNode*, int>::Iterator iter;
    if (_serialMap.end() == (iter = _serialMap.find(node)))
    {
        return -1;
    }

    return iter.value();
}

int NodeManager::nodeStep(DataNode* node)
{
    int step = 0;
    DataNode* parent = node->parent();
    while (parent)
    {
        parent = parent->parent();
        step++;
    }

    return (step - 1);
}

//获取节点所有的父节点
void NodeManager::allParentNode(DataNode* child, QList<DataNode*>& parentList)
{
    DataNode* parent = child->parent();
    while (parent)
    {
        parentList.push_back(parent);
        parent = parent->parent();
    }
}