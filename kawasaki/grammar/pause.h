#ifndef PauseNODE_H
#define PauseNODE_H

#include "astnode.h"

namespace Language
{
    class PauseNode : public ASTNode
    {
    public:
        PauseNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
