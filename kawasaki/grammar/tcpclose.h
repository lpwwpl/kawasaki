#ifndef TCPCLOSENODE_H
#define TCPCLOSENODE_H

#include "astnode.h"

namespace Language
{
    class TCPCloseNode : public ASTNode
    {
    public:
        TCPCloseNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
