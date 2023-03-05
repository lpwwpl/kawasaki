#ifndef ASTNODE_H
#define ASTNODE_H

#include <QVariant>
#include "IAction.h"
#include "parser.tab.hpp"

typedef Language::Parser::token token;
#define SPACE " "
#define INTENT "    "
namespace Language
{
    class ASTNode : public  IAction
    {
    public:
        ASTNode(int type = token::VoidType);
        virtual ~ASTNode();
        virtual QVariant Execute();
        int Type();
        virtual QString toString(uint level=0);
        virtual QString toRaw(uint level = 0);
        void SetPrefix(bool value) { _prefix = value; }
        //virtual QString toRaw(uint level = 0);
    protected:
        bool _prefix;
        int _type;

    };
}

#endif // ASTNODE_H
