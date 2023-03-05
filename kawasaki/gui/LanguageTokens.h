#ifndef PROTOTYPES_H
#define PROTOTYPES_H

//--- At lib includes -----------------------------------------------------------------------------
#include <QString>
#include <QVector>
#include <QTreeWidgetItem>


//-------------------------------------------------------------------------------------------------
class LanguageToken //: public QTreeWidgetItem
{
public:
    LanguageToken(const QString &sName);
    LanguageToken(LanguageToken *pParent,
                  const QString &sName);

    virtual ~LanguageToken();

    const QString& getName() const;

    void add(LanguageToken *pItem);
    void remove(LanguageToken *pItem);

    void setLine(int nLine);
    int getLine() const;

    void setParent(LanguageToken *pToken);
    LanguageToken *getParent();

    const LanguageToken* getParent() const;

    QVector<LanguageToken*> m_vChilds;
    QString m_sName;
    LanguageToken *m_pParent;
    int m_nLine;
};


//-------------------------------------------------------------------------------------------------
class Script : public LanguageToken
{
public:
    Script(const QString &sName);
};


//-------------------------------------------------------------------------------------------------
class ClassDefinition : public LanguageToken
{
public:
    ClassDefinition(LanguageToken *pParent, const QString &sName);
};


//-------------------------------------------------------------------------------------------------
class FunctionDefinition : public LanguageToken
{
public:
    FunctionDefinition(LanguageToken *pParent,
                       const QString &sName,
                       const QString &sArgs);

    QString m_sArgs;
};

#endif // PROTOTYPES_H
