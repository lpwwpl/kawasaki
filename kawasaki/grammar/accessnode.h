#ifndef ACCESSNODE_H
#define ACCESSNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class AccessNode: public ASTNode
    {
    public:
        AccessNode(QString * name, ASTNode* dim=NULL);
        
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
            QString _name;
            ASTNode* _dim;
            QString _realVar;
    };
}

#endif // ASSIGNMENTNODE_H
