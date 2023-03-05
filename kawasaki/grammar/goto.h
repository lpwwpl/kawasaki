#ifndef GOTONODE_H
#define GOTONODE_H

#include "astnode.h"

namespace Language
{
    class GotoNode : public ASTNode
    {
    public:
        GotoNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;

    private:
        ASTNode* _expression;
        ASTNode* _topParent;
    };
}

#endif // FUNCTIONCALLNODE_H
