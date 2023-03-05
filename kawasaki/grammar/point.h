#ifndef POINT_H
#define POINT_H

#include "astnode.h"

namespace Language
{
    class PointNode : public ASTNode
    {
    public:
        PointNode(ASTNode*, ASTNode*, ASTNode*, ASTNode*, ASTNode*);
        PointNode(ASTNode*, ASTNode*, int);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression_left;
        ASTNode* _expression_right;
        ASTNode* _expression_shift;
        ASTNode* _expression_s_x;
        ASTNode* _expression_s_y;
        ASTNode* _expression_s_z;
        ASTNode* _signal_num_stm;
        int _type;
    };
}

#endif // FUNCTIONCALLNODE_H
