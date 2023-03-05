#include "tcpclose.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TCPCloseNode::TCPCloseNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TCPCloseNode::Execute()
    {
        std::cout << QString("%1 %2").arg("base").arg(_expression->Execute().toString()).toStdString() << std::endl;

        return ASTNode::Execute();
    }

    QString TCPCloseNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("#self.");
        str.append("tcp_close");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
