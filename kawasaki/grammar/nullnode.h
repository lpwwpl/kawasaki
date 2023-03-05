#ifndef NULLNODE_H
#define NULLNODE_H

#include "astnode.h"

namespace Language
{
    class NullNode : public ASTNode
    {
    public:
        NullNode();
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
