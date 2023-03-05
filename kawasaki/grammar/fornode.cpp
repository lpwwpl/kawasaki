#include "fornode.h"
#include "assignmentnode.h"
#include "symboltable.h"
namespace Language
{
    ForNode::ForNode(ASTNode * assignment, ASTNode * to_expression, ASTNode* step, ASTNode * function_body)
        : _assignment(assignment),
          _to_expression(to_expression),
         _step(step),
         _function_body(function_body)
    {
    }

    QVariant ForNode::Execute()
    {
        AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_assignment);
        assign->Execute();

        int stepInt = 1;
        if(_step)
         stepInt = _step->Execute().toInt();

        QString realName = assign->getRealVar();
        QString name = assign->getName();
        dimListType* dim = assign->getDimListType();
        QVariant v=SymbolTable::Instance().GetActivationRecord()->GetVariableValue(realName);
        int v_int = v.toInt();
        int to = _to_expression->Execute().toInt();
        for(; v_int <=to;)
        {
            if(_function_body)
                _function_body->Execute();
            v_int = v_int + stepInt;
            SymbolTable::Instance().GetActivationRecord()->AssignVariable(name, v_int, dim);
        }
        return ASTNode::Execute();
    }

    QString ForNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("for");
        str.append(" ");
        AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_assignment);
        str.append(assign->VarStr());
        str.append(" ");
        str.append("in");
        str.append(" ");
        str.append("range");
        str.append("(");
        str.append(_to_expression->toString());
        str.append(")");
        str.append(":");
        str.append("\n");
        level = level + 1;
        str.append(_function_body->toString(level));
        return str; 
    }
}
