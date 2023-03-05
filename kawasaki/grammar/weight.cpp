#include "weight.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    WeightNode::WeightNode(ASTNode* expression)
        : _expression(expression)
    {
    } 
    QVariant WeightNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString WeightNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("weight");
        str.append("(");
        str.append("\"");
        str.append(_expression->toString());
        str.append("\"");
        str.append(")");
        return str;
    }

}
