#include "casenode.h"

namespace Language
{
    CaseNode::CaseNode(ASTNode * expression, ASTNode * body)
        : _body(body),
          _expression(expression)
    {
    }

    QVariant CaseNode::Execute()
    {
        if (_body)
        {
            return _body->Execute();            
        }
            
        else 
            return  ASTNode::Execute();
    }

    QString CaseNode::toString(uint level)
    {
        QString str = "";
        str.append(_body->toString(level));
        return str;
    }
}
