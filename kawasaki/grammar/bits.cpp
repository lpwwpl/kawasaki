#include "bits.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    BitsNode::BitsNode(ASTNode* expression_start_bit, ASTNode* expression_bits,int type) : _expression_start_bit(expression_start_bit),
        _expression_bits(expression_bits),_type(type)
    {

    }
    QVariant BitsNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString BitsNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        QString start_bit = _expression_start_bit->toString();
        QString bits = _expression_bits->toString();
     
        
        if (_type == 0)
        {
            str.append("self.bits");
            str.append("(");
            str.append(start_bit);
            str.append(",");
            str.append(bits);
            str.append(")");
        }
        else
        {
            str.append(start_bit);
            str.append(",");
            str.append(bits);
        }
     
        return str;
    }
}
