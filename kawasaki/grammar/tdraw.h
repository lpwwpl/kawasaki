#ifndef TDRAWNODE_H
#define TDRAWNODE_H

#include "astnode.h"

namespace Language
{
    class TDrawNode : public ASTNode
    {
    public:
        TDrawNode(ASTNode* expression=0);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;

    };
}

#endif // FUNCTIONCALLNODE_H
