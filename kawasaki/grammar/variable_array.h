#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include "astnode.h"

namespace Language
{
    class AST_variable_array_int : public ASTNode
    {
    private:
        //friend class Evaluate; friend class CodeGen;
        //friend class Traverse;
        string array_name;
        AST_expression* index;
    public:
        AST_variable_array_int(string array_name, AST_expression* index);
 
    };
}

#endif // FUNCTIONCALLNODE_H
