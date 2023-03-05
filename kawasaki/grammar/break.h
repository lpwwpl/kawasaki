#ifndef BREAKNODE_H
#define BREAKNODE_H

#include "astnode.h"

namespace Language
{
    class BreakNode : public ASTNode
    {
    public:
        BreakNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
