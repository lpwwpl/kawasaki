#include "c1move.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    C1MoveNode::C1MoveNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant C1MoveNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("c1move");
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

    QString C1MoveNode::toString(uint level)
    {
        QString str = "";
        str.append("c1move");
        return str;
    }
}
