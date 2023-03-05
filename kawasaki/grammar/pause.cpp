#include "pause.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    PauseNode::PauseNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant PauseNode::Execute()
    {
        //QVariant v = _expression->Execute();
        QString str = "";
        str.append("pause");

        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString PauseNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("pause");
        str.append("(");
        //str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
