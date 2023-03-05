#ifndef TCPSENDNODE_H
#define TCPSENDNODE_H

#include "astnode.h"

namespace Language
{
    class TCPSendNode : public ASTNode
    {
    public:
        TCPSendNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
