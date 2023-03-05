#ifndef DECODE_H
#define DECODE_H

#include "astnode.h"

namespace Language
{
    class DecodeNode : public ASTNode
    {
    public:
        DecodeNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
