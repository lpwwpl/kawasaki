#include "ldepart.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    LDepartNode::LDepartNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant LDepartNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("here");
        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString LDepartNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("ldepart");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
