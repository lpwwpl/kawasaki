#ifndef TCPCONNECTNODE_H
#define TCPCONNECTNODE_H

#include "astnode.h"

namespace Language
{
    class TCPConnectNode : public ASTNode
    {
    public:
        TCPConnectNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
