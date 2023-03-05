#include "pointx.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    PointXNode::PointXNode(ASTNode* expression_left, ASTNode* _expression_right) : _expression_left(expression_left),
        _expression_right(_expression_right)
    {

    }
    QVariant PointXNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString PointXNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        QString left = _expression_left->toString();
        QString right = _expression_right->toString();
        str.append(left);
        str.append("[0]");
        str.append("=");
        str.append(right);
        str.append("[0]");
        return str;
    }
}
