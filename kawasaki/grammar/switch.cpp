#include "switch.h"
#include "switch_case_list.h"
#include "casenode.h"

namespace Language
{
    SWitchNode::SWitchNode(ASTNode * expression, ASTNode * caseLists, ASTNode * defaultCase)
        : _caseLists(caseLists),
          _defaultCase(defaultCase),
          _expression(expression)
    {
    }

    QVariant SWitchNode::Execute()
    {
        int var = _expression->Execute().toInt();
        SWitchCaseListNode* caseLists = dynamic_cast<SWitchCaseListNode*> (_caseLists);

        if (!caseLists) return ASTNode::Execute();
        QMap<int, CaseNode*> key_values;
        for (auto it = caseLists->begin(); it != caseLists->end(); it++)
        {
            CaseNode* caseNode = dynamic_cast<CaseNode*>(*it);
            int key = caseNode->_expression->Execute().toInt();
            if (var == key)
            {
                return caseNode->Execute();
            }           
            //key_values.insert(key, caseNode);
        }

       
        /*
        QMap<int, CaseNode*>::iterator it;
        for (it=key_values.begin();it!=key_values.end();it++)
        {
          
        }*/
        //caseLists
    
        return ASTNode::Execute();
    }

    QString SWitchNode::toString(uint level)
    {
        QString str = "";

        //numbers = {
        //  2: self.work2,
        //  3 : self.work3,
        //  4 : self.work4,
        //  5 : self.work5,
        //  6 : self.work6
        //}

        //    method = numbers.get(kdata.jobnum, self.other)
        //    if method:
        //method()

        QMap<int, ASTNode* > cases;
        ASTNode* key = _expression;
        for (int i = 0; i < level ; i++)
        {
            str.append("    ");
        }
        str.append("numbers={");
        str.append("\n");
        SWitchCaseListNode* caseLists = dynamic_cast<SWitchCaseListNode*> (_caseLists);

        QMap<int, CaseNode*> key_values;
        
        for (auto it = caseLists->begin(); it != caseLists->end(); it++)
        {
            for (int i = 0; i < level + 1; i++)
            {
                str.append("    ");
            }
            CaseNode* caseNode = dynamic_cast<CaseNode*>(*it);
            int key = caseNode->_expression->Execute().toInt();
            str.append(QString::number(key));
            str.append(":");
            str.append("\n");
            str.append(caseNode->toString(level));

        }
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("}");
        str.append("\n");
        for (int i = 0; i < level ; i++)
        {
            str.append("    ");
        }
        QString temp = QString("method=numbers.get(%1)").arg(key->toString());

        str.append(temp);
        str.append("\n");
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("method()");

        return str;
    }
}
