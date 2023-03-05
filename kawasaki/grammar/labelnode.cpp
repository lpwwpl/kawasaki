#include "labelnode.h"
#include "returnnode.h"
#include "symboltable.h"

namespace Language
{
    LabelNode::LabelNode(ASTNode* id) : _id(id)
    {
        IdentifierNode* node = dynamic_cast<IdentifierNode*>(_id);
        if (node)
        {
            QString _id_str = node->_name;
            QString new_id_str = "";
            if (!_id_str.startsWith("."))
            {
                new_id_str.append(".");
                new_id_str.append(_id_str);

            }
            node->SetPrefix(false);
            node->_name = new_id_str;
            return;
        }

    }

    QVariant LabelNode::Execute()
    {
        QString str = "";

      

        //std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }

    QString LabelNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("label");
        str.append(" ");     
        
        NumberLiteralNode* nNode = dynamic_cast<NumberLiteralNode*>(_id);
        if (nNode)
        {
            
            QString labelName = ".x";
            labelName.append(nNode->toString());
            str.append(labelName);
        }
        else
        {
            str.append(".");
            str.append(_id->toString());
        }

        return str;
    }
}
