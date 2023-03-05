#ifndef BITSNODE_H
#define BITSNODE_H

#include "astnode.h"

namespace Language
{
    class BitsNode : public ASTNode
    {
    public:
        BitsNode(ASTNode*, ASTNode*,int );
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression_bits;
        ASTNode* _expression_start_bit;
        int _type;
    };
}

#endif // FUNCTIONCALLNODE_H
