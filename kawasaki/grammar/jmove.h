#ifndef JMOVENODE_H
#define JMOVENODE_H

#include "astnode.h"

namespace Language
{
    class JMoveNode : public ASTNode
    {
    public:
        JMoveNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
