#ifndef BASENODE_H
#define BASENODE_H

#include "astnode.h"

namespace Language
{
    class BaseNode : public ASTNode
    {
    public:
        BaseNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
