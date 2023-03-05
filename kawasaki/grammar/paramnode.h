#ifndef PARAMNODE_H
#define PARAMNODE_H

#include "astnode.h"

namespace Language
{
    class ParamNode : public ASTNode
    {
    public:
        ParamNode(ASTNode* expression=0);
        ParamNode(ASTNode* expression,int,bool,bool);
        ParamNode(ASTNode* expression, int,bool);
        ParamNode(ASTNode* expression, int type);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
        bool _always;
        bool _fine;
        int _type; //mm/s,mm/min
    };
}

#endif // FUNCTIONCALLNODE_H
