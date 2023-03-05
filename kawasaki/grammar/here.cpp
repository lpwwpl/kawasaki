#include "here.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    HereNode::HereNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant HereNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("here");
        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString HereNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("here");
        return str;
    }
}
