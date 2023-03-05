#ifndef LMOVENODE_H
#define LMOVENODE_H

#include "astnode.h"

namespace Language
{
    class LMoveNode : public ASTNode
    {
    public:
        LMoveNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
