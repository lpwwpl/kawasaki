#ifndef DATANODE_H
#define DATANODE_H

#include <QString>
#include <QDate>
#include <QList>
#include <QMap>
#include <QStringList>

#include "DrawGantt.h"

class DataNode
{
public:
    enum Type{Root, Summary, Task, Unknown};
    DataNode();
    ~DataNode();

    Type type() {return _type;}
    void setType(Type type) { _type = type;}
    QString serialNo();
    void setSerialNo(const QString& serial);

    Qt::CheckState checkState(int col);
    void setCheckState(int col, Qt::CheckState state);

    float codeNo();
    void setCodeNo(float num);

    QString name();
    void setName(const QString& name);

    QDate planBeginDate();
    void setPlanBeginDate(const QDate& date);

    QDate planEndDate();
    void setPlanEndDate(const QDate& date);

    int planDays();
    void setPlanDays(int days);

    QDate realBeginDate();
    void setRealBeginDate(const QDate& date);

    QDate realEndDate();
    void setRealEndDate(const QDate& date);

    int realDays();
    void setRealDays(int days);

    int totalDays();
    void setTotalDays(int days);

    QString mask();
    void setMask(const QString& mask);

    DrawGantt* drawGantt() { return _drawGantt; }

public:
    DataNode* parent();
    DataNode& setParent(DataNode* value);
    QList<DataNode*>& children();
    void insertChild(int index, DataNode* child);
    DataNode* removeChild(int index);
    
private:
    DataNode* _parent;
    QList<DataNode*> _children;

private:
    QString _serialNo;
    Type _type;

    //keyÎªÁÐºÅ
    QMap<int, Qt::CheckState> _stateMap;

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

    DrawGantt* _drawGantt;
};

#endif // DATANODE_H