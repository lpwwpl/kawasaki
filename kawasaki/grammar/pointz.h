#ifndef POINTZNODE_H
#define POINTZNODE_H

#include "astnode.h"

namespace Language
{
    class PointZNode : public ASTNode
    {
    public:
        PointZNode(ASTNode* ,ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression_left;
        ASTNode* _expression_right;
    };
}

#endif // FUNCTIONCALLNODE_H
