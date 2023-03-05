#ifndef HOMENODE_H
#define HOMENODE_H

#include "astnode.h"

namespace Language
{
    class HomeNode : public ASTNode
    {
    public:
        HomeNode(ASTNode* expression=0);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
