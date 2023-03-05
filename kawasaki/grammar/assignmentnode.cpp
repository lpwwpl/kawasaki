#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    AssignmentNode::AssignmentNode(QString* name, ASTNode* expression_bits, ASTNode* expression, ASTNode* dim ):_expression_bits(expression_bits),
        _expression(expression),_dim(dim),_name(*name),_src(NULL)
    {

    }

    AssignmentNode::AssignmentNode(ASTNode* src, ASTNode* expression,  ASTNode* dim) :_src(src),_expression(expression),_dim(dim), _expression_bits(NULL), _name("")
        
    {

    }

    AssignmentNode::AssignmentNode(QString * name, ASTNode * expression, ASTNode* dim/*dimListType* dim*/):_name(*name),  _expression(expression),_dim(dim),
        _expression_bits(NULL), _src(NULL)
    {
        ListNode<ASTNode>* exprNode = dynamic_cast<ListNode<ASTNode>*>(expression);
        ASTNode* oneexpression = expression;
        if (exprNode)
        {
            oneexpression = exprNode->at(0);
        }
        int typeActual = oneexpression->Type();
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimListType* dimList=NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimList);
        _realVar = SymbolTable::Instance().CalcRealVarName(*name, dimList);
        int typeExpected = SymbolTable::Instance().VariableType(_realVar);
       
        if (typeExpected == -1)
        {
            if (!_realVar.startsWith("."))
            { 
                ///////////GlobalRecord::Instance().AssignVariable(_name, _expression->Execute(), dimList);
                //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);
            }
            return;
        }

        if (typeActual != typeExpected)
        {
            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }
    }

    QVariant AssignmentNode::Execute()
    {     
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimListType* dimList = NULL;
        if (dimNode)
            dimList = &(dimNode->tempDimList);

        SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _expression->Execute(), dimList);

        return ASTNode::Execute();
    }
    QString AssignmentNode::VarStr()
    {
        QString str = "";

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
        dimRawType* dimRawList = NULL;
        if (dimNode)
            dimRawList = &(dimNode->tempDimRawList);
        int ndim;
        if (dimRawList != NULL)
        {
            ndim = dimRawList->size();
            str.append("[");
        }
        else
            ndim = 0;

        for (int i = 0; i < ndim; i++)
        {
            QString dimVar = dimRawList->at(i)->toString();
            str.append(dimVar);
            if (i < (ndim - 1))
                str.append(",");
        }
        if (ndim > 0)
            str.append("]");
        return str;
    }
    QString AssignmentNode::toString(uint level )
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }



        if (_name == "VAL")
        {

        }

        if (_name == "BITS" && _expression_bits)
        {
            //self.bits_assign(kdata.jobnum, 41, 8)
            str.append("self.bits_assign");
            str.append("(");
            str.append(_expression->toString());
            str.append(",");
            str.append(_expression_bits->toString());
            str.append(")");
            return str;
        }    
        if (_src)
        {
            str.append(_src->toString());
        }
        else
        {
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
        }
        DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        dimRawType* dimRawList = NULL;
        if (dimNode)
            dimRawList = &(dimNode->tempDimRawList);
        int ndim;
        if (dimRawList != NULL)
        {
            ndim = dimRawList->size();
            str.append("[");
        }
        else
            ndim = 0;

        for (int i = 0; i < ndim; i++)
        {
            QString dimVar = dimRawList->at(i)->toString();
            str.append(dimVar);
            if (i < (ndim - 1))
                str.append(",");
        }
        if(ndim>0)
            str.append("]");
        str.append("=");

        BuildInNode* buildIn = dynamic_cast<BuildInNode*>(_expression);
        if (buildIn)
        {
            str.append(buildIn->toString());
            return str;
        }

        str.append(_expression->toString());
        return str;
    }
}
