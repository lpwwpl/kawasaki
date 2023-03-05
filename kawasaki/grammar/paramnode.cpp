#include "paramnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    ParamNode::ParamNode(ASTNode* expression)
        : _expression(expression), _always(false), _fine(false), _type(0)
    {
    }
    ParamNode::ParamNode(ASTNode* expression,int type)
        : _expression(expression), _always(false), _fine(false), _type(type)
    {
    }
    ParamNode::ParamNode(ASTNode* expression, int type,bool always) : _expression(expression), _always(always), _fine(false),_type(type)
    {

    }
    ParamNode::ParamNode(ASTNode* expression, int type,bool always, bool fine) : _expression(expression), _always(always), _fine(fine), _type(type)
    {

    }
    QVariant ParamNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString ParamNode::toString(uint level)
    {
        QString str = "";

        str.append(_expression->toString());

        switch (_type)
        {
        case 1:
            str.append(" ");
            str.append("MM/S");
            break;
        case 2:
            str.append(" ");
            str.append("MIN/S");
            break;
        default:
            break;
        }  
     
        if (_always)
        { 
            str.append(" ");
            str.append("ALWAYS");  
        }
        if (_fine)
        {
            str.append(" ");
            str.append("FINE");
        }

        return str;
    }
}
