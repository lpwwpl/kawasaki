#include "whilenode.h"

namespace Language
{
    WhileNode::WhileNode(ASTNode * expression, ASTNode * body)
            :  _body(body),
             _expression(expression)
    {
    }

    QVariant WhileNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString WhileNode::toString(uint level)
    {
        return QString("");
    }
}
