#ifndef CASENODE_H
#define CASENODE_H

#include "astnode.h"

namespace Language
{
    class CaseNode: public ASTNode
    {
    public:
        CaseNode(ASTNode * expression, ASTNode * body);
        QVariant Execute() override;
        //void SetVar(ASTNode* var) { _var = var; }
        QString toString(uint level = 0) override;
    public:
        ASTNode* _expression;

    private:
            ASTNode * _body;


            //ASTNode* _var;
    };
}

#endif // IFNODE_H
