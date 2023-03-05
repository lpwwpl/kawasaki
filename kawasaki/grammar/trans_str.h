#ifndef TRANSSTRNODE_H
#define TRANSSTRNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class TransStrNode : public ListNode<ASTNode>
    {
    public:
        TransStrNode(ASTNode* value);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        int Type()
        {
            return   token::TextType;
        }
    private:
        //QString _value;
    };
}

#endif // NUMBERLITERALNODE_H
