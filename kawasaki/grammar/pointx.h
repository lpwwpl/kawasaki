#ifndef POINTXNODE_H
#define POINTXNODE_H

#include "astnode.h"

namespace Language
{
    class PointXNode : public ASTNode
    {
    public:
        PointXNode(ASTNode*, ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression_right;
        ASTNode* _expression_left;
        int _type;
    };
}

#endif // FUNCTIONCALLNODE_H
