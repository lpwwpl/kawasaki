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
    //�ж��¾ɸ��ڵ��Ƿ����
    if (_parent != value)
    {
        //�ж��¸��ڵ��Ƿ�ΪNULL
        if (value != NULL)
        {
            if (_parent != NULL)
            {
                //�ж�ԭ���ڵ�ĺ����б����Ƿ���ڵ�ǰ�ڵ�
                if (_parent->children().indexOf(this, 0) >= 0)
                {
                    //ԭ���ڵ�͵�ǰ�ڵ�����ϵ
                    _parent->children().removeOne(this);
                }
            }

            //�����µĸ��ڵ�
            _parent = value;
            //���¸��ڵ���й���
            if (_parent->children().indexOf(this, 0) < 0)
            {
                _parent->children().append(this);
            }
        }
        else
        {
            //�ж�ԭ���ĸ��ڵ��Ƿ�ΪNULL
            if (_parent != NULL)
            {
                //ԭ���ڵ�͵�ǰ�ڵ�����ϵ
                _parent->children().removeOne(this);
            }

            //�����¸��ڵ�ΪNULL
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

    //�ж�childԭ���ĸ��ڵ��Ƿ�Ϊnull�������Ϊ��Ҫ���ԭ���Ĺ�ϵ��
    if (child->_parent != NULL)
    {
        child->setParent(NULL);
    }

    //���õ�ǰ��childe�ĸ��ڵ�Ϊ��ǰ�ڵ�
    child->_parent = this;

    //���뵽�����б���
    _children.insert(index, child);
}

DataNode* DataNode::removeChild(int index)
{
    int size = _children.size();
    if (index > size)
    {
        return NULL;
    }

    //�ҵ���ǰ�Ľڵ�
    DataNode* node = _children.at(index);

    //�Ӻ��ӽڵ��б���ɾ����ǰ�ڵ�
    _children.removeAt(index);

    //�Ե�ǰ�ڵ�ĸ��ڵ�����Ϊ��
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