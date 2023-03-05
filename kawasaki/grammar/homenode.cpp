#include "homenode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    HomeNode::HomeNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant HomeNode::Execute()
    {
        if (_expression)
            std::cout << QString("%1 %2").arg("home").arg(_expression->Execute().toString()).toStdString() << std::endl;
        else
            std::cout << QString("%1").arg("home").toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString HomeNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("home");
        str.append("(");
        if(_expression)
            str.append(_expression->toString());
        else
            str.append("1");
        str.append(")");
        return str;
    }

}
