#ifndef PRINTNODE_H
#define PRINTNODE_H

#include "astnode.h"

namespace Language
{
    class PrintNode: public ASTNode
    {
    public:
        PrintNode(ASTNode * expression);
        PrintNode(ASTNode* , ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
            ASTNode * _expression;
            ASTNode* _target;
    };
}

#endif // PRINTNODE_H
