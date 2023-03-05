#ifndef JAPPRO_H
#define JAPPRO_H

#include "astnode.h"

namespace Language
{
    class JapproNode : public ASTNode
    {
    public:
        JapproNode(ASTNode* expression, ASTNode* delta);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
        ASTNode* _delta;
    };
}

#endif // FUNCTIONCALLNODE_H
