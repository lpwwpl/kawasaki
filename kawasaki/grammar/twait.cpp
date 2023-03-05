#include "twait.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TWaitNode::TWaitNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TWaitNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString TWaitNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("twait");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
