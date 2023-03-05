#ifndef DRIVENODE_H
#define DRIVENODE_H

#include "astnode.h"

namespace Language
{
    class DriveNode : public ASTNode
    {
    public:
        DriveNode(ASTNode* expression=0);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
