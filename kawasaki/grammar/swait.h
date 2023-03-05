#ifndef SWAITNODE_H
#define SWAITNODE_H

#include "astnode.h"
#include "signal_nums_node.h"
namespace Language
{
    class SWaitNode : public ASTNode
    {
    public:
        SWaitNode(/*ASTNode* expression,*/SignalNumsNode* num_lists);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        //ASTNode* _expression;
        SignalNumsNode* _num_lists;
    };
}

#endif // FUNCTIONCALLNODE_H
