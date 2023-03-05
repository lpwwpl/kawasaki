#include "align.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    AlignNode::AlignNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant AlignNode::Execute()
    {
        std::cout << QString("%1").arg("align").toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString AlignNode::toString(uint level )
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("align");
        str.append("()");
        return str;
    }
}
