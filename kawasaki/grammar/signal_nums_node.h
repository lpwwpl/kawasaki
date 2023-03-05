#ifndef SIGNALNUMSNODE_H
#define SIGNALNUMSNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class SignalNumsNode : public ListNode<ASTNode>
    {
    public:
        SignalNumsNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level=0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
