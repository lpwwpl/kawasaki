#include "type.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TypeNode::TypeNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TypeNode::Execute()
    {
        std::cout << QString("%1 %2").arg("type").arg(_expression->Execute().toString()).toStdString() << std::endl;
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString TypeNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("type");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
