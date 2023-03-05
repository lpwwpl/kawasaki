#include "draw.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    DrawNode::DrawNode(ASTNode* expression)
        : _expression(expression)
    {
    }
    QVariant DrawNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString DrawNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("draw");
        str.append("(");
        str.append("\"");
        str.append(_expression->toString());
        str.append("\"");
        str.append(")");
        return str;
    }

}
