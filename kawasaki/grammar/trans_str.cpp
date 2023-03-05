#include "trans_str.h"
#include <QVector>
namespace Language
{
    TransStrNode::TransStrNode(ASTNode* value)
    {
        if(value)
        push_back(value);
    }

    QVariant TransStrNode::Execute()
    {
        QVector<double> v;
        int count = this->size();
        for (int i = 0; i < count; i++)
        {
            //ASTNode* elem = this->at(i);
            //v.push_back(elem);
        }
        //QVariant var = QVariant::fromValue(v);
        //return var;
        return 0;
        //return QVariant();
    }
    QString TransStrNode::toString(uint level)
    {
        QString str = "";
        int count = this->size();
        for (int i = 0; i < count; i++)
        {
            ASTNode* elem = this->at(i);
            str.append(elem->toString());
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        return str;
    }
}

