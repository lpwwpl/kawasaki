#include "tcprecv.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TCPRecvNode::TCPRecvNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TCPRecvNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString TCPRecvNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("#self.");
        str.append("tcp_recv");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
