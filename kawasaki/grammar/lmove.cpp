#include "lmove.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    LMoveNode::LMoveNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant LMoveNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("lmove");
        str.append(" ");
        if (v.isValid())
        {
            QVector<double> vv = v.value<QVector<double>>();
            for (int i = 0; i < vv.size(); i++)
            {
                str.append(QString::number(vv.at(i)));
                str.append(" ");
            }           
        }
        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString LMoveNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("lmove");
        str.append("(");
        str.append(_expression->toString());
        str.append(",");
        AccessNode* access = dynamic_cast<AccessNode*>(_expression);
        if(access)
        {
            str.append(_expression->toRaw());
        }
        else
        {
            str.append("\"");
            str.append(_expression->toRaw());
            str.append("\"");
        }
      
        str.append(")");
        return str;
    }
}
