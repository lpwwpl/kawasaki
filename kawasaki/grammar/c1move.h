#ifndef C1MOVENODE_H
#define C1MOVENODE_H

#include "astnode.h"

namespace Language
{
    class C1MoveNode : public ASTNode
    {
    public:
        C1MoveNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
