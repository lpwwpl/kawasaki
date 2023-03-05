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
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return ASTNode::Execute();
    }
}
