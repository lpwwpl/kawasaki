#include "numberliteralnode.h"

namespace Language
{
    NumberLiteralNode::NumberLiteralNode(double value)
        : ASTNode(token::NumberType),
          _value(value)
    {
    }

    QVariant NumberLiteralNode::Execute()
    {
        return QString("%1").arg(_value);
    }

    QString NumberLiteralNode::toString(uint level)
    {
        return QString::number(_value);
    }
}

