#ifndef VALNODE_H
#define VALNODE_H

#include "astnode.h"

namespace Language
{
    class VALNode : public ASTNode
    {
    public:
        VALNode(ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
