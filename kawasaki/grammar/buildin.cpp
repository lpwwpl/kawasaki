#include "buildin.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    BuildInNode::BuildInNode(QString* name, ASTNode* expresion) : _name(*name),
        _expression(expresion),_type(0)
    {

    }
    QVariant BuildInNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString BuildInNode::toString(uint level)
    {
        QString str = "";

        if (_name == "BITS")
        {
            str.append("self.bits");
            str.append("(");
            str.append(_expression->toString());
            str.append(")");
        }
        return str;
    }
}
