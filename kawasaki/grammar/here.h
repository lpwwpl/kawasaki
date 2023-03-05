#ifndef HERE_H
#define HERE_H

#include "astnode.h"

namespace Language
{
    class HereNode : public ASTNode
    {
    public:
        HereNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
