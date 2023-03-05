#include "dimnumnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{

    DimNumsNode::DimNumsNode(ASTNode* expression)
    {
        NumberLiteralNode* node = dynamic_cast<NumberLiteralNode*>(expression);
        if (node)
        {
            //tempDimList.push_back(node->Execute().toInt());
            tempDimRawList.push_back(node);
            return;
        }
        IdentifierNode* id_node = dynamic_cast<IdentifierNode*>(expression);
        if(id_node)
        {
            tempDimRawList.push_back(id_node);
            //tempDimList.push_back(id_node->Execute().toInt());
        }
        OperatorNode* opNode = dynamic_cast<OperatorNode*>(expression);
        if (opNode)
        {
            tempDimRawList.push_back(opNode);
        }
    }

    QVariant DimNumsNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return ASTNode::Execute();
    }

    void DimNumsNode::push_back(ASTNode* expression)
    {
        NumberLiteralNode* node = dynamic_cast<NumberLiteralNode*>(expression);
        if (node)
        {
            tempDimRawList.push_back(node);
            //tempDimList.push_back(node->Execute().toInt());
            return;
        }
        IdentifierNode* id_node = dynamic_cast<IdentifierNode*>(expression);
        if (id_node)
        {
            tempDimRawList.push_back(node);
            //tempDimList.push_back(id_node->Execute().toInt());
        }
        OperatorNode* opNode = dynamic_cast<OperatorNode*>(expression);
        if (opNode)
        {
            tempDimRawList.push_back(opNode);
        }
    }

    QString DimNumsNode::toString(uint level)
    {
        QString str = "";
        str.append("[");
        int count = tempDimRawList.size();
        for(int i = 0;i<count;i++)
        {
            str.append(tempDimRawList[i]->toRaw());
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append("]");
        return str;
    }
    //DimNumNode::DimNumNode(ASTNode* expression)
    //{
    //    push_back(expression);
    //}

    //QVariant DimNumNode::Execute()
    //{
    //    //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
    //    return ASTNode::Execute();
    //}
}
