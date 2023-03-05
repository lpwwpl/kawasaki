#include "accessnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    AccessNode::AccessNode(QString * name,  ASTNode* dim/*dimListType* dim*/):_name(*name),  _dim(dim)
    {
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimListType* dimList=NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimList);
        _realVar = SymbolTable::Instance().CalcRealVarName(*name, dimList);
        int typeExpected = SymbolTable::Instance().VariableType(_realVar);
        if (typeExpected == -1)
        {
            return;
        }
    }

    QVariant AccessNode::Execute()
    {
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimListType* dimList = NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimList);
        QString realVar = SymbolTable::Instance().CalcRealVarName(_name, dimList);
        QVariant v = SymbolTable::Instance().GetActivationRecord()->GetVariableValue(realVar);

        //std::cout << toString().toStdString() ;
        return v;
        //return ASTNode::Execute();
    }
    QString AccessNode::toRaw(uint level)
    {
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimRawType* dimList = NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimRawList);
        QString raw = "";
        raw.append("\"");
        raw.append(_name);
        int ndim;
        if (dimList != NULL)
            ndim = dimList->size();
        else
            ndim = 0;

        QString ret = "";


        if (ndim > 0)
        {
            raw.append("[");

            for (int i = 0; i < ndim; i++)
            {
                raw.append("{},");
            }

            raw = raw.mid(0, raw.size() - 1);
            raw.append("]");

            raw.append("\"");
            ret.append("self.str_format(");
            ret.append(raw);
            ret.append(",");

            for (int i = 0; i < ndim; i++)
            {
                QString temp = "";
                ASTNode* elem = dimList->at(i);

                //int index = dimList->at(i);
                QString dimVarRaw = QString("%1,").arg(elem->toString());
                ret.append(dimVarRaw);
            }
            ret = ret.mid(0, ret.size() - 1);
            ret.append(")");
        }
        return ret;
    }

    QString AccessNode::toString(uint level)
    {
       
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        QString temp = _name;
        if (!_name.startsWith("."))
        {
            str.append("kdata.");
        }
        else
        {
            temp.replace(0, 1, "");
        }
        if (_name.startsWith("#"))
        {
            temp.replace(0, 1, "_");
        }
        if (_name.startsWith("$"))
        {
            temp.replace(0, 1, "");
        }
        str.append(temp);

        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimRawType* dimList = NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimRawList);

        int ndim;
        if (dimList != NULL)
            ndim = dimList->size();
        else
            ndim = 0;

        if (ndim > 0)
        {
            str.append("[");
        }
            
        for (int i = 0; i < ndim; i++)
        {
            ASTNode* elem = dimList->at(i);
            //int index = dimList->at(i);
            QString dimVar = QString("%1,").arg(elem->toString());
            str.append(dimVar);
        }
        if (ndim > 0)
        {
            str = str.mid(0, str.size() - 1);
            str.append("]");
        }        

        return str;
    }
}
