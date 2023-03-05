#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class AssignmentNode: public ASTNode
    {
    public:
        AssignmentNode(QString * name, ASTNode * expression, ASTNode* dim=NULL);
        AssignmentNode(QString* name, ASTNode*, ASTNode* expression, ASTNode* dim);
        AssignmentNode(ASTNode* ,  ASTNode* expression, ASTNode* dim = NULL);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString VarStr();
        QString getRealVar() { return _realVar; }
        QString getName() { return _name; }
        dimListType* getDimListType()
        {
            DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
            dimListType* dimList = NULL;
            if (dimNode)
                dimList = &(dimNode->tempDimList);
            return dimList;
        }

    private:
            QString _name;
            QString _realVar;
            ASTNode * _expression;
            ASTNode* _src;
            ASTNode* _dim;
            ASTNode* _expression_bits;
    };
}

#endif // ASSIGNMENTNODE_H
