#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionCallNode: public ASTNode
    {
    public:
        FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList=NULL);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
            QString * _name;
            ListNode<ASTNode> * _expressionList;
    };
}

#endif // FUNCTIONCALLNODE_H
