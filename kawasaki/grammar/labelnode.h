#ifndef LABELNODE_H
#define LABELNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
{
class LabelNode: public ASTNode
{
public:
    ASTNode* _id;

    public:
        LabelNode(ASTNode * id);
        QVariant Execute() override;
        QString toString(uint level = 0) ;
    };
}

#endif // STATEMENTLISTNODE_H
