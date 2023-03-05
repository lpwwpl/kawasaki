#ifndef ACCURACY_H
#define ACCURACY_H

#include "astnode.h"

namespace Language
{
    class AccuracyNode : public ASTNode
    {
    public:
        AccuracyNode(ASTNode* expression=0);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
