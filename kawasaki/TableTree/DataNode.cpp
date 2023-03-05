#include "DataNode.h"

DataNode::DataNode()
{
    _type = Unknown;

    _serialNo = "";
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

    _parent = NULL;
    _children.clear();

    _drawGantt = new DrawGantt();
}

DataNode::~DataNode()
{
}

QString DataNode::serialNo()
{
    return _serialNo;
}

void DataNode::setSerialNo(const QString& serial)
{
    _serialNo = serial;
}

float DataNode::codeNo()
{
    return _codeNo;
}

void DataNode::setCodeNo(float num)
{
    _codeNo = num;
}

QString DataNode::name()
{
    return _name;
}

void DataNode::setName(const QString& name)
{
    _name = name;
}

QDate DataNode::planBeginDate()
{
    return _planBeginDate;
}

void DataNode::setPlanBeginDate(const QDate& date)
{
    _planBeginDate = date;
}

QDate DataNode::planEndDate()
{
    return _planEndDate;
}

void DataNode::setPlanEndDate(const QDate& date)
{
    _planEndDate = date;
}

int DataNode::planDays()
{
    return _planDays;
}

void DataNode::setPlanDays(int days)
{
    _planDays = days;
}

QDate DataNode::realBeginDate()
{
    return _realBeginDate;
}

void DataNode::setRealBeginDate(const QDate& date)
{
    _realBeginDate = date;
}

QDate DataNode::realEndDate()
{
    return _realEndDate;
}

void DataNode::setRealEndDate(const QDate& date)
{
    _realEndDate = date;
}

int DataNode::realDays()
{
    return _realDays;
}

void DataNode::setRealDays(int days)
{
    _realDays = days;
}

int DataNode::totalDays()
{
    return _totalDays;
}

void DataNode::setTotalDays(int days)
{
    _totalDays = days;
}

QString DataNode::mask()
{
    return _mask;
}

void DataNode::setMask(const QString& mask)
{
    _mask = mask;
}

DataNode* DataNode::parent() 
{
    return _parent;
}

DataNode& DataNode::setParent(DataNode* value)
{
    //判断新旧父节点是否相等
    if (_parent != value)
    {
        //判断新父节点是否为NULL
        if (value != NULL)
        {
            if (_parent != NULL)
            {
                //判断原父节点的孩子列表中是否存在当前节点
                if (_parent->children().indexOf(this, 0) >= 0)
                {
                    //原父节点和当前节点解除关系
                    _parent->children().removeOne(this);
                }
            }

            //设置新的父节点
            _parent = value;
            //和新父节点进行关联
            if (_parent->children().indexOf(this, 0) < 0)
            {
                _parent->children().append(this);
            }
        }
        else
        {
            //判断原来的父节点是否为NULL
            if (_parent != NULL)
            {
                //原父节点和当前节点解除关系
                _parent->children().removeOne(this);
            }

            //设置新父节点为NULL
            _parent = NULL;
        }
    }

    return *this;
}

QList<DataNode*>& DataNode::children() 
{
    return _children;
}

void DataNode::insertChild(int index, DataNode* child)
{
     int size = _children.size();
    if (index > size)
    {
        return;
    }

    //判断child原来的父节点是否为null，如果不为需要解除原来的关系先
    if (child->_parent != NULL)
    {
        child->setParent(NULL);
    }

    //设置当前的childe的父节点为当前节点
    child->_parent = this;

    //插入到孩子列表中
    _children.insert(index, child);
}

DataNode* DataNode::removeChild(int index)
{
    int size = _children.size();
    if (index > size)
    {
        return NULL;
    }

    //找到当前的节点
    DataNode* node = _children.at(index);

    //从孩子节点列表中删除当前节点
    _children.removeAt(index);

    //对当前节点的父节点设置为空
    node->_parent = NULL;
    
    return node;
}

Qt::CheckState DataNode::checkState(int col)
{
    return _stateMap[col];
}

void DataNode::setCheckState(int col, Qt::CheckState state)
{
    _stateMap[col] = state;
}