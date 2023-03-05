#include "activationrecord.h"
#include "dimnumnode.h"

ActivationRecord::ActivationRecord()
{
    //_variables
    QMap<QString, QVariant> globals = GlobalRecord::Instance()._variables;
    for (QString key:globals.keys())
    {
        _variables.insert(key, globals.value(key));
    }
    _curFunc = NULL;
}

QString ActivationRecord::CalcRealVarName(QString name, dimListType* tempDimList)
{
    QString realVar = name;

    int ndim;
    if (tempDimList != NULL)
        ndim = tempDimList->size();
    else
        ndim = 0;

    for (int i = 0; i < ndim; i++)
    {
        QString dimVar = QString("_%1").arg(tempDimList->at(i));
        realVar = realVar.append(dimVar);
    }
    return realVar;
}
void ActivationRecord::AssignVariable(QString name, QVariant value, dimListType* tempDimList)
{
    QString realVar = CalcRealVarName(name,tempDimList);
    std::cout << QString("%1 = %2").arg(realVar).arg(value.toString()).toStdString() << std::endl;
    _variables[realVar] = value;
        if (!realVar.startsWith("."))
        {
            GlobalRecord::Instance().AssignVariable(name, value, tempDimList);
        }
        //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);
 }
    


void ActivationRecord::DeclareVariable(QString name, dimListType* tempDimList)
{
    QString realVar = CalcRealVarName(name, tempDimList);
    bool isDefinedVar = isDefined(realVar);
    if (!isDefinedVar)
    {
        _variables[realVar] = QVariant(0);
    }
 }


QVariant ActivationRecord::GetVariableValue(QString name)
{
    return _variables[name];
}

void ActivationRecord::SetReturnValue(QVariant value)
{
    _returnValue = value;
}

QVariant ActivationRecord::GetReturnValue()
{
    return _returnValue;
}

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::unique_ptr<GlobalRecord> GlobalRecord::_instance = nullptr;
std::once_flag GlobalRecord::_onceFlag;

GlobalRecord::GlobalRecord()
{
   
}

GlobalRecord& GlobalRecord::Instance()
{
    std::call_once(_onceFlag,
        [] {
            _instance.reset(new GlobalRecord);
        });
    return *_instance.get();
}
void GlobalRecord::AssignVariable(QString name, QVariant value, dimListType* tempDimList)
{
    QString realVar = CalcRealVarName(name, tempDimList);
    _variables[realVar] = value;
}
QVariant GlobalRecord::GetVariableValue(QString name)
{
    return _variables[name];
}

void GlobalRecord::DeclareVariable(QString name, dimListType* tempDimList)
{
    QString realVar = CalcRealVarName(name, tempDimList);
    bool isDefinedVar = isDefined(realVar);
    if (!isDefinedVar)
    {
        _variables[realVar] = QVariant();
    }
}
bool GlobalRecord::isDefined(QString varName) {
    if (_variables.find(varName) == _variables.end()) return false;
    else return true;//return _variables[varName];
}
QString GlobalRecord::CalcRealVarName(QString name, dimListType* tempDimList)
{
    QString realVar = name;

    int ndim;
    if (tempDimList != NULL)
        ndim = tempDimList->size();
    else
        ndim = 0;

    for (int i = 0; i < ndim; i++)
    {
        QString dimVar = QString("_%1").arg(tempDimList->at(i));
        realVar = realVar.append(dimVar);
    }
    return realVar;
}