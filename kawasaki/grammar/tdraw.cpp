#include "tdraw.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TDrawNode::TDrawNode(ASTNode* expression)
        : _expression(expression)
    {
    } 
    QVariant TDrawNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString TDrawNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("tdraw");
        str.append("(");
        str.append("\"");
        str.append(_expression->toString());
        str.append("\"");
        str.append(")");
        return str;
    }

}
