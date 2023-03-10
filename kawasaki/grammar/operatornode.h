#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "astnode.h"

namespace Language
{
    class OperatorNode: public ASTNode
    {
    public:
        OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2 = nullptr);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0)override;
    private:
        ASTNode * _op1;
        ASTNode * _op2;
        int _operator;
    };
}

#endif // OPERATORNODE_H
