#ifndef TCPRECVNODE_H
#define TCPRECVNODE_H

#include "astnode.h"

namespace Language
{
    class TCPRecvNode : public ASTNode
    {
    public:
        TCPRecvNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
