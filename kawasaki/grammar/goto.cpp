#include "goto.h"

#include "symboltable.h"
#include "errors.h"
#include "listnode.h"

namespace Language
{
    GotoNode::GotoNode(ASTNode* expression)
        : _expression(expression)
    {
        this->_topParent = NULL;

        IdentifierNode* node = dynamic_cast<IdentifierNode*>(expression);
        if (node)
        {
            QString _id_str = node->_name;
            QString new_id_str = "";
            if (!_id_str.startsWith("."))
            {
                new_id_str.append(".");
                new_id_str.append(_id_str);

            }
            node->_name = new_id_str;
            node->SetPrefix(false);

        }

    }


    QVariant GotoNode::Execute()
    {
        this->_topParent = SymbolTable::Instance().GetActivationRecord()->GetCurNode();
        //std::cout << QString("%1 %2").arg("goto").arg(_expression->Execute().toString()).toStdString() << std::endl;
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        Language::FunctionNode* func = SymbolTable::Instance().GetActivationRecord()->GetCurFunctionNode();
        if (!func) return QVariant();
        StatementListNode* body = (func->GetBody());

        StatementListNode* goto_statementList = new StatementListNode(NULL);
        bool isInsert = false;

        int index = 0;
        for (auto statement : *body)
        {
            //auto pLabel = dynamic_cast<LabelNode*>(statement);
            //if (pLabel)
            //{
            //    auto id = dynamic_cast<IdentifierNode*>(pLabel->_id);
            //    QString name = (id->_name);
            //    if (name == _expression->toString())
            //    {
            //        isInsert = true;
            //    }
            //}

            //search  label Node
            //label's neibor node
            if (isInsert)
            {
                goto_statementList->push_back(statement);
            }
            //auto dynamic_cast<ListNode<ASTNode*>*>(statement);
           

            index++;
        }
        goto_statementList->Execute();
        return ASTNode::Execute();
    }
    QString GotoNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("goto");
        str.append(" ");
        NumberLiteralNode* nNode = dynamic_cast<NumberLiteralNode*>(_expression);
        if (nNode)
        {
            QString labelName = ".x";
            labelName.append(nNode->toString());
            str.append(labelName);
        }
        else
        {
            str.append(".");
            str.append(_expression->toString());
        }
        return str;
    }
}
