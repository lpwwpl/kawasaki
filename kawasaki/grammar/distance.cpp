#include "distance.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    DistanceNode::DistanceNode(ASTNode* expression) : _expression(expression)
    {

    }
    QVariant DistanceNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString DistanceNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.distance");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
     
        return str;
    }
}
