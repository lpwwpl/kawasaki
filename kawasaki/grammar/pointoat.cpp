#include "pointoat.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    PointOATNode::PointOATNode(ASTNode* expression_left, ASTNode* _expression_right) : _expression_left(expression_left),
        _expression_right(_expression_right)
    {

    }
    QVariant PointOATNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString PointOATNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        QString left = _expression_left->toString();
        QString right = _expression_right->toString();
        str.append(left);
        str.append("[3]");
        str.append("=");
        str.append(right);
        str.append("[3]");
        str.append("\n");
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append(left);
        str.append("[4]");
        str.append("=");
        str.append(right);
        str.append("[4]");
        str.append("\n");
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append(left);
        str.append("[5]");
        str.append("=");
        str.append(right);
        str.append("[5]");

        return str;
    }
}
