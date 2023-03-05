#ifndef STOPNODE_H
#define STOPNODE_H

#include "astnode.h"

namespace Language
{
    class StopNode : public ASTNode
    {
    public:
        StopNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
