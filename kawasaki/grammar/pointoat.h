#ifndef POINTOAT_NODE_H
#define POINTOAT_NODE_H

#include "astnode.h"

namespace Language
{
    class PointOATNode : public ASTNode
    {
    public:
        PointOATNode(ASTNode*, ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression_left;
        ASTNode* _expression_right;
    };
}

#endif // FUNCTIONCALLNODE_H
