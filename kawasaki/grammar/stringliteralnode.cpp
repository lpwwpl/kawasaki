#include "stringliteralnode.h"

namespace Language
{
    StringLiteralNode::StringLiteralNode(QString * value)
        : ASTNode(token::TextType)
    {
        _value = value->mid(1, value->length()-2);
    }

    QVariant StringLiteralNode::Execute()
    {
        return _value;
    }

    QString StringLiteralNode::toString(uint level)
    {
        QString str = "";
        str.append("\"");
        str.append(_value);
        str.append("\"");
        return str;
    }
}

