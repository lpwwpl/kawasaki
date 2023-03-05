#ifndef LAPPRO_H
#define LAPPRO_H

#include "astnode.h"

namespace Language
{
    class LapproNode : public ASTNode
    {
    public:
        LapproNode(ASTNode* expression,ASTNode* delta);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
        ASTNode* _delta;
    };
}

#endif // FUNCTIONCALLNODE_H
