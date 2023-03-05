#include "functioncallnode.h"


#include "errors.h"
#include "symboltable.h"

namespace Language
{
    FunctionCallNode::FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList)
            :  _name(name),
             _expressionList(expressionList)
    {
        auto function = SymbolTable::Instance().Function(name);
        if (!function) { return; }
        auto expectedArguments = function->Arguments();

        _type = function->Type();

        if (expectedArguments->size() != expressionList->size())
        {
            std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << name->toStdString() << ")\n";
            exit(EXIT_FAILURE);
        }

     /*   for (size_t i=0; i<expectedArguments->size(); i++)
        {
            int typeExpected = expectedArguments->at(i)->Type();
            int typeActual = expressionList->at(i)->Type();
            if (typeExpected != typeActual)
            {
                std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << std::endl;
                std::cerr << "in function: " << name->toStdString() << std::endl;
                std::cerr << "argument: " << i << std::endl;
                exit(EXIT_FAILURE);
            }
        }*/


    }

    QVariant FunctionCallNode::Execute()
    {
        /// ////////////////////////////////////////
        std::cout << toString().toStdString();

        // TODO: Maybe wrong order
        for (auto expression: *_expressionList)
            SymbolTable::Instance().PushArgument(expression->Execute());
        SymbolTable::Instance().PushArgument((int)_expressionList->size());
        return SymbolTable::Instance().Function(_name)->Execute();
    }

    QString FunctionCallNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append(_name);
        str.append("(");
        for (size_t i = 0; i < _expressionList->size(); i++)
        {
            ASTNode* arg = _expressionList->at(i);
            str.append(arg->toString());
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append(")");
        return str;
    }
}
