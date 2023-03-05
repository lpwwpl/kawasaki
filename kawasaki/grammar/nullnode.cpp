#include "nullnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    NullNode::NullNode()
    {
    }

    QVariant NullNode::Execute()
    {


        return ASTNode::Execute();
    }

    QString NullNode::toRaw(uint level )
    {
        return "NULL";
    }
    QString NullNode::toString(uint level)
    {
        return "None";
    }
}
