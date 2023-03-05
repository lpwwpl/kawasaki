#include "pulse.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    PulseNode::PulseNode(ASTNode* expression,ASTNode* delta)
        : _expression(expression),_delta(delta)
    {
    }

    QVariant PulseNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("pulse");
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

    QString PulseNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("pulse");
        str.append("(");
        str.append(_expression->toString());
        str.append(",");
        str.append(_delta->toString());
        str.append(")");
        return str;
    }
}
