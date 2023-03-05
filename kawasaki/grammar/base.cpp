#include "base.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    BaseNode::BaseNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant BaseNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString BaseNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("base");
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
