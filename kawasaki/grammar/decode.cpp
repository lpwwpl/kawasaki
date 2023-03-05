#include "decode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    DecodeNode::DecodeNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant DecodeNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString DecodeNode::toString(uint level)
    {
        QString str = "self.";
        str.append("decode");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
