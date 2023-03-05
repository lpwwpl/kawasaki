#ifndef TWAITNODE_H
#define TWAITNODE_H

#include "astnode.h"

namespace Language
{
    class TWaitNode : public ASTNode
    {
    public:
        TWaitNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
