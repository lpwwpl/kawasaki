#ifndef TRANSNODE_H
#define TRANSNODE_H

#include "astnode.h"

namespace Language
{
    class TransNode : public ASTNode
    {
    public:
        TransNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
