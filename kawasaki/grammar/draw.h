#ifndef DRAWNODE_H
#define DRAWNODE_H

#include "astnode.h"

namespace Language
{
    class DrawNode : public ASTNode
    {
    public:
        DrawNode(ASTNode* expression=0);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
