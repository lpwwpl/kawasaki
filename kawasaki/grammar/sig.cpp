#include "sig.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    SigNode::SigNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant SigNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString SigNode::toString(uint level)
    {
        QString str = "self.sig";
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
