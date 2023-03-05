#include "jappro.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    JapproNode::JapproNode(ASTNode* expression,ASTNode* delta)
        : _expression(expression),_delta(delta)
    {
    }

    QVariant JapproNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("jappro");
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
        str.append(",");
        str.append(_delta->Execute().toString());
        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString JapproNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("jappro");
        str.append("(");
        str.append(_expression->toString());
        str.append(",");
        AccessNode* access = dynamic_cast<AccessNode*>(_expression);
        if (access)
        {
            str.append(_expression->toRaw());
        }
        else
        {
            str.append("\"");
            str.append(_expression->toRaw());
            str.append("\"");
        }
        str.append(",");
        str.append(_delta->toString());
        str.append(")");
        return str;
    }
}
