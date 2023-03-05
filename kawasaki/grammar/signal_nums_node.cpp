#include "signal_nums_node.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    SignalNumsNode::SignalNumsNode(ASTNode* expression)
    {
        push_back(expression);
    }

    QVariant SignalNumsNode::Execute()
    {
        //for (auto statement : *this)
        //{
        //    statement->Execute();
        //    if (dynamic_cast<NumberLiteralNode*>(statement))
        //        break;
        //}
        QString str = "";
        QString param = "";
        int count = this->size();
        for (int i = 0 ;i< count;i++)
        {
            param = QString("%1,").arg(this->at(i)->Execute().toInt());
        }
        if(param.size()>1)
            param = param.mid(0, param.size() - 1);
        //std::cout << param.toStdString() << std::endl;
        return param;
    }

    QString SignalNumsNode::toString(uint level)
    {
        QString str = "";
        int count = this->size();
        for (int i = 0; i < count; i++)
        {
            ASTNode*  elem = this->at(i);
            if(!elem)
                str.append(",");
            else
            { 
                QString elemstr = elem->toString();
                str.append(elemstr);
                str.append(",");
            }
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        return str;
    }
}
