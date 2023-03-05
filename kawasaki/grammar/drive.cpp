#include "drive.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{

    DriveNode::DriveNode(ASTNode* expression)
        : _expression(expression)
    {
    }
    QVariant DriveNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString DriveNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("drive");
        str.append("(");
        str.append("\"");
        str.append(_expression->toString());
        str.append("\"");
        str.append(")");
        return str;
    }

}
