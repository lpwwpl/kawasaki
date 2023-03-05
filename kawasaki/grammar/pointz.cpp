#include "pointz.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    PointZNode::PointZNode(ASTNode* expression_left, ASTNode* _expression_right) : _expression_left(expression_left),
        _expression_right(_expression_right)
    {

    }
    QVariant PointZNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString PointZNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        QString left = _expression_left->toString();
        QString right = _expression_right->toString();
        str.append(left);
        str.append("[2]");
        str.append("=");
        str.append(right);
        str.append("[2]");
        return str;
    }
}
