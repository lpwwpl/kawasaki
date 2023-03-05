#include "tcpconnect.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TCPConnectNode::TCPConnectNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TCPConnectNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString TCPConnectNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("#self.");
        str.append("tcp_connect");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
