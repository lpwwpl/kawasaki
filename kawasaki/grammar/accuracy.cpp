#include "accuracy.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    AccuracyNode::AccuracyNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant AccuracyNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("accuracy");
        str.append(" ");
        str.append(v.toString());
        return ASTNode::Execute();
    }

    QString AccuracyNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("accuracy");
        str.append("(");
        str.append("\"");
        str.append(_expression->toString());
        str.append("\"");
        str.append(")");
        return str;
    }
}
