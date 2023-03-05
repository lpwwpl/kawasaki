#include "tcpstatus.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TCPStatusNode::TCPStatusNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TCPStatusNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString TCPStatusNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("#self.");
        str.append("tcp_status");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
