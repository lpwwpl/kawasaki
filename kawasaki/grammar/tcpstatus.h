#ifndef TCPSTATUSNODE_H
#define TCPSTATUSNODE_H

#include "astnode.h"

namespace Language
{
    class TCPStatusNode : public ASTNode
    {
    public:
        TCPStatusNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
