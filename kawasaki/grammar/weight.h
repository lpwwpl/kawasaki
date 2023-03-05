#ifndef WEIGHT_H
#define WEIGHT_H

#include "astnode.h"

namespace Language
{
    class WeightNode : public ASTNode
    {
    public:
        WeightNode(ASTNode* expression=0);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;

    };
}

#endif // FUNCTIONCALLNODE_H
