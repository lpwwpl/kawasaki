#include "switch_case_list.h"

#include "symboltable.h"
#include "errors.h"
#include "casenode.h"

namespace Language
{
    SWitchCaseListNode::SWitchCaseListNode(ASTNode* caseexpr)
    {
        push_back(caseexpr);
    }

    QVariant SWitchCaseListNode::Execute()
    {
        //for (auto statement : *this)
        //{
        //    statement->Execute();
        //    if (dynamic_cast<NumberLiteralNode*>(statement))
        //        break;
        //}

        return ASTNode::Execute();
    }

    QString SWitchCaseListNode::toString(uint level)
    {


        return QString("");
    }
}
