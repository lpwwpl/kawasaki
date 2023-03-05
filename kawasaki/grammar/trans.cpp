#include "trans.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    TransNode::TransNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TransNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("jmove");
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

    QString TransNode::toString(uint level)
    {
        QString str = "";
        str.append(_expression->toString());
        return str;
    }
}
