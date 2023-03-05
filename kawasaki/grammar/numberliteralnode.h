#ifndef NUMBERLITERALNODE_H
#define NUMBERLITERALNODE_H

#include "astnode.h"

namespace Language
{
    class NumberLiteralNode : public ASTNode
    {
    public:
        NumberLiteralNode(double value);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        double _value;
    };
}

#endif // NUMBERLITERALNODE_H
