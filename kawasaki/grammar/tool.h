#ifndef TOOLNODE_H
#define TOOLNODE_H

#include "astnode.h"

namespace Language
{
    class ToolNode : public ASTNode
    {
    public:
        ToolNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
