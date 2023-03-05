#ifndef DOUNTILNODE_H
#define DOUNTILNODE_H

#include "astnode.h"

namespace Language
{
    class DoUntilNode: public ASTNode
    {
    public:
        DoUntilNode(ASTNode * expression, ASTNode * funcbody);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
            ASTNode * _funcbody;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
