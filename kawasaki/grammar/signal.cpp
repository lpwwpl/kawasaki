#include "signal.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    SignalNode::SignalNode(/*ASTNode* expression,*/ SignalNumsNode* num_lists)
        : /*_expression(expression),*/_num_lists(num_lists)
    {
    }

    QVariant SignalNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString SignalNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("signal");
        str.append("(");
        str.append(_num_lists->toString());
        str.append(")");
        return str;
    }
}
