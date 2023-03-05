#ifndef SPEED_H
#define SPEED_H

#include "astnode.h"

enum eType
{
    eMM_S = 0,
    eMM_MIN =1,
    ePERcent = 2,
};
namespace Language
{
    class SpeedNode : public ASTNode
    {
    public:
        SpeedNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
 
    };
}

#endif // FUNCTIONCALLNODE_H
