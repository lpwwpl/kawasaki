#ifndef ALIGNNODE_H
#define ALIGNNODE_H

#include "astnode.h"

namespace Language
{
    class AlignNode : public ASTNode
    {
    public:
        AlignNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
