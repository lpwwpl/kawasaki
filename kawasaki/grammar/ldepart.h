#ifndef LDEPART_H
#define LDEPART_H

#include "astnode.h"

namespace Language
{
    class LDepartNode : public ASTNode
    {
    public:
        LDepartNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
