#include "returnnode.h"
#include "symboltable.h"

namespace Language
{
    ReturnNode::ReturnNode(ASTNode * expression)
        : _expression(expression)
    {
        _type = token::FNULL;
        if(expression)
        _type = _expression->Type();
    }

    QVariant ReturnNode::Execute()
    {
        //std::cout << QString("%1").arg("return").toStdString() << std::endl;

        QVariant returnValue;
        if(!_expression)
            return ASTNode::Execute();
        returnValue = _expression->Execute();
        SymbolTable::Instance().GetActivationRecord()->SetReturnValue(returnValue);
        return ASTNode::Execute();
    }
    QString ReturnNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("return");
        str.append(" ");
        if(_expression)
            str.append(_expression->toString());
        return str;
    }
}
