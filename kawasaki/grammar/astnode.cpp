#include "astnode.h"


namespace Language
{
    ASTNode::ASTNode(int type)
        :_type(type), _prefix(true)
    {
    }

    QVariant ASTNode::Execute()
    {
        return QVariant();
    }
    QString ASTNode::toString(uint level)
    {
        return QString("");
    }
    QString ASTNode::toRaw(uint level)
    {
        return toString(level);
    }
    ASTNode::~ASTNode()
    {
    }

    int ASTNode::Type()
    {
        return _type;
    }
}
