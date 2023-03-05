#ifndef DECOMPOSE_H
#define DECOMPOSE_H

#include "astnode.h"

namespace Language
{
    class DecomposeNode : public ASTNode
    {
    public:
        DecomposeNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
