#include "tcpsend.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TCPSendNode::TCPSendNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TCPSendNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString TCPSendNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("#self.");
        str.append("tcp_send");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
