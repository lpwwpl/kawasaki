#ifndef PULSE_H
#define PULSE_H

#include "astnode.h"

namespace Language
{
    class PulseNode : public ASTNode
    {
    public:
        PulseNode(ASTNode* expression, ASTNode* delta);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
        ASTNode* _delta;
    };
}

#endif // FUNCTIONCALLNODE_H
