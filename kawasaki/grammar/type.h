#ifndef TYPENODE_H
#define TYPENODE_H

#include "astnode.h"

namespace Language
{
    class TypeNode : public ASTNode
    {
    public:
        TypeNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
