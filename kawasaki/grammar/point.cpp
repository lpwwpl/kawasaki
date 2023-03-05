#include "point.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    PointNode::PointNode(ASTNode* expression_left, ASTNode* expression_shift, ASTNode* expression_s_x, ASTNode* expression_s_y, ASTNode* expression_s_z)
        : _expression_left(expression_left), _expression_shift(expression_shift), _expression_s_x(expression_s_x),
        _expression_s_y(expression_s_y), _expression_s_z(expression_s_z)
    {

    }
    PointNode::PointNode(ASTNode* expression_left, ASTNode* node, int type) : _expression_left(expression_left), _type(type)
    {
        _expression_shift = NULL;
        _expression_s_x = NULL;
        _expression_s_y = NULL;
        _expression_s_z = NULL;
        _expression_right = NULL;
        _signal_num_stm = NULL;
        switch (_type)
        {
        case 0:
            _expression_right = node;
            break;
        case 1:
            _signal_num_stm = node;
            break;
        default:
            break;
        }
       

    }
    QVariant PointNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString PointNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        QString left = _expression_left->toString();
        str.append(left);
        str.append("=");


        if (_expression_shift)
        {
            str.append("self.shift(");
            QString shift = _expression_shift->toString();
            str.append(shift);
            str.append(",");

            QString x = _expression_s_x->toString();
            str.append(x);
            str.append(",");
            QString y = _expression_s_y->toString();
            str.append(y);
            str.append(",");
            QString z = _expression_s_z->toString();
            str.append(z);
            str.append(")");
        }
        else if(_expression_right)
        {
            str.append(_expression_right->toString());
        }
        else if (_signal_num_stm)
        {
            str.append("[");
            str.append(_signal_num_stm->toString());
            str.append("]");
        }

        return str;
    }
}
