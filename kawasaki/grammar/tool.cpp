#include "tool.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    ToolNode::ToolNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant ToolNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString ToolNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("tool");
        str.append("(");
        str.append(_expression->toString());
        str.append(",");
        str.append("\"");
        str.append(_expression->toRaw());
        str.append("\"");
        str.append(")");
        return str;
    }
}
