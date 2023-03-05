#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include "astnode.h"

namespace Language
{
    class IdentifierNode : public ASTNode
    {
    public:
        IdentifierNode(QString * name);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0);
    public:
        QString _name;
    };
}

#endif // IDENTIFIERNODE_H
