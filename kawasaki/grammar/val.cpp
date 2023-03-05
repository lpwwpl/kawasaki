#include "val.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    VALNode::VALNode(ASTNode* expression) : _expression(expression)
    {

    }
    QVariant VALNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString VALNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.val");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
     
        return str;
    }
}
