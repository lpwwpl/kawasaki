#ifndef BUILDINNODE_H
#define BUILDINNODE_H

#include "astnode.h"

namespace Language
{
    class BuildInNode : public ASTNode
    {
    public:
        BuildInNode(QString*, ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        QString _name;
        ASTNode* _expression;
        int _type;
    };
}

#endif // FUNCTIONCALLNODE_H
