#include "decompose.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    DecomposeNode::DecomposeNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant DecomposeNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("decompose");
        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString DecomposeNode::toString(uint level)
    {
        QString str = "";
        str.append("decompose");
        return str;
    }
}
