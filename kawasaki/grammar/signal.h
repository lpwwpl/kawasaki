#ifndef SIGNALNODE_H
#define SIGNALNODE_H

#include "astnode.h"
#include "signal_nums_node.h"
namespace Language
{
    class SignalNode : public ASTNode
    {
    public:
        SignalNode(/*ASTNode* expression,*/ SignalNumsNode* num_lists);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        //ASTNode* _expression;
        SignalNumsNode* _num_lists;
    };
}

#endif // FUNCTIONCALLNODE_H
