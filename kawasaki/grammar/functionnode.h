#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionNode: public ASTNode
    {
    public:
        FunctionNode(int type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body);
        QVariant Execute() override;
        ListNode<ParameterNode> * Arguments() const ;
        QString toString(uint level = 0) override;
        StatementListNode* GetBody() { return _body; }
        ListNode<ParameterNode>* GetArguments() { return _arguments; }
        QString GetName() { return _name; }
    private:
        ListNode<ParameterNode> * _arguments;
        StatementListNode * _body;
        QString _name;
    };
}

#endif // FUNCTIONNODE_H
