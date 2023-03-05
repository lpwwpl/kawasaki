#include "functionnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    FunctionNode::FunctionNode(int type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body)
            : ASTNode(type),
              _name(*name),
              _arguments(arguments),
              _body(body)
    {
         SymbolTable::Instance().DefineFunction(name,this);

         for (auto statement: *body)
         {
             if (auto pReturn = dynamic_cast<ReturnNode *>(statement))
             {
                 //int typeActual = pReturn->Type();
                 //if (statement->Type() != _type)
                 //{
                 //    std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(_type).toStdString() << " (line: " << lineNumber << ")" << std::endl;
                 //    exit(EXIT_FAILURE);
                 //}
             }
         }
         SymbolTable::Instance().ClearVariables();

    }

    QVariant FunctionNode::Execute()
    {
        SymbolTable::Instance().PushAR();
        SymbolTable::Instance().GetActivationRecord()->SetCurFunctionNode(this);
        int argc = SymbolTable::Instance().PopArgument().toInt();
        if (argc != (int)_arguments->size())
        {
            std::cerr << STACK_CORRUPTED;
            exit(EXIT_FAILURE);
        }

        for (int i=0; i<argc; i++)
        {
            QVariant arg = SymbolTable::Instance().PopArgument();
            QString name = _arguments->at(argc-i-1)->Name();
            SymbolTable::Instance().GetActivationRecord()->AssignVariable(name, arg);
        }

        _body->Execute();

        QVariant retVal = SymbolTable::Instance().GetActivationRecord()->GetReturnValue();

        SymbolTable::Instance().GetActivationRecord()->SetCurFunctionNode(NULL);
        SymbolTable::Instance().PopAR();

        return retVal;
    }

    ListNode<ParameterNode> * FunctionNode::Arguments() const
    {
        return _arguments;
    }

    QString FunctionNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str += "@allow_goto";
        str += "\n";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str += "def";
        str += SPACE;
        str += _name;
        str += "(self)";
        str += ":";
        str += "\n";
        //str += INTENT;
        //str += _arguments->toString();
        str.append(_body->toString(level+1));
        return str;
    }
}

