#ifndef SIGNODE_H
#define SIGNODE_H

#include "astnode.h"

namespace Language
{
    class SigNode : public ASTNode
    {
    public:
        SigNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
