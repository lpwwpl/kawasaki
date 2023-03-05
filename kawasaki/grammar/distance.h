#ifndef DISTANCE_H
#define DISTANCE_H

#include "astnode.h"

namespace Language
{
    class DistanceNode : public ASTNode
    {
    public:
        DistanceNode(ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
