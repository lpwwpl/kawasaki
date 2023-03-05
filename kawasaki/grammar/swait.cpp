#include "swait.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    SWaitNode::SWaitNode(/*ASTNode* expression,*/SignalNumsNode* num_lists)
        : /*_expression(expression),*/ _num_lists(num_lists)
    {
    }

    QVariant SWaitNode::Execute()
    {
        std::cout << QString("%1 %2").arg("swait").arg(_num_lists->toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString SWaitNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("swait");
        str.append("(");
        str.append(_num_lists->toString());
        str.append(")");
        return str;
    }
}
