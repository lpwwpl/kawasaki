#include "do_until.h"

namespace Language
{
    DoUntilNode::DoUntilNode(ASTNode* expression, ASTNode* funcbody)
        : _funcbody(funcbody),
          _expression(expression)
    {


    }

    QVariant DoUntilNode::Execute()
    {
        bool isLoop = false;
        while(true)
        {
            _funcbody->Execute();
            isLoop = _expression->Execute().toBool();
            if (isLoop)break;
        }
        //do
        //{
        //    _funcbody->Execute();
        //    isLoop = _expression->Execute().toBool();
        //} while (!isLoop);
        return ASTNode::Execute();
    }

    QString DoUntilNode::toString(uint level)
    {
        QString str = "";
        return str; 
    }
}
