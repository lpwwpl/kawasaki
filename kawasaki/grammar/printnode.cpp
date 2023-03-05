#include "printnode.h"

namespace Language
{
    PrintNode::PrintNode(ASTNode * expression)
            :   _expression(expression)
    {
    }
    PrintNode::PrintNode(ASTNode* target,ASTNode* expression)
        : _target(target),_expression(expression)
    {
    }
    QVariant PrintNode::Execute()
    {
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString PrintNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("print");
        str.append("(");
        if (_target)
        {

        }        
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
