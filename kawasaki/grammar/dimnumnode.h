#ifndef DIMNUMNODE_H
#define DIMNUMNODE_H

#include "astnode.h"
#include "listnode.h"



namespace Language
{
    //varDeclarationNodeType varDeclaration;
    //class DimNumNode : public ListNode<ASTNode>
    //{
    //public:
    //    DimNumNode(ASTNode* expression);
    //    QVariant Execute() override;

    //private:
    //    ASTNode* _expression;
    //};
    typedef std::vector<int> dimListType;
    typedef std::vector<ASTNode*> dimRawType;
    class DimNumsNode : public ASTNode {
    public:
        //QString varName;                  /* var Name */
        dimListType tempDimList;
        dimRawType tempDimRawList;
        //QString realName;
        DimNumsNode(ASTNode* expression);
        QVariant Execute() override;
        void push_back(ASTNode* expression);
        QString toString(uint level = 0) override;
       /* void execute()
        {
            int ndim;
            if (tempDimList != NULL)
                ndim = tempDimList->size();
            else
                ndim = 0;

            for (int i = 0; i < ndim; i++)
            {
                QString dimVar = QString("_ % 1").arg(i);
                realName = varName.append(dimVar);
            }
        }*/
    };
}

#endif // FUNCTIONCALLNODE_H
