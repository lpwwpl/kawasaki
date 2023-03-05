#include "break.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    BreakNode::BreakNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant BreakNode::Execute()
    {
        //QVariant v = _expression->Execute();
        QString str = "";
        str.append("break");

        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString BreakNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("break_");
        str.append("(");
        //str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
