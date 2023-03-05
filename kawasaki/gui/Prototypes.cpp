#include "Prototypes.h"

//-------------------------------------------------------------------------------------------------
#include "Exceptions.h"


//-------------------------------------------------------------------------------------------------
//
//
// class LanguageToken
//
//
//-------------------------------------------------------------------------------------------------

LanguageToken::LanguageToken(const QString& sName)
    :m_vChilds()
    ,m_sName(sName)
    ,m_pParent(NULL)
    ,m_nLine(-1)
{}

//-------------------------------------------------------------------------------------------------
LanguageToken::~LanguageToken()
{
    for (int i=0; i<m_vChilds.size(); ++i)
    {
        LanguageToken *pToken = m_vChilds[i];
        delete pToken;
    }

    m_vChilds.clear();
}

//-------------------------------------------------------------------------------------------------
const QString& LanguageToken::getName() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::setParent(LanguageToken *pToken)
{
    if (m_pParent!=NULL)
        m_pParent->remove(this);

    m_pParent = pToken;
}

//-------------------------------------------------------------------------------------------------
LanguageToken* LanguageToken::getParent()
{
    return m_pParent;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::setLine(int nLine)
{
    m_nLine = nLine;
}

//-------------------------------------------------------------------------------------------------
int LanguageToken::getLine() const
{
    return m_nLine;
}

//-------------------------------------------------------------------------------------------------
const QVector<LanguageToken*>& LanguageToken::getChilds() const
{
    return m_vChilds;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::add(LanguageToken *pToken)
{
    if (pToken==NULL || m_vChilds.indexOf(pToken)!=-1)
        return;

    LanguageToken *pParent = pToken->getParent();
    if (pParent!=NULL)
        throw InternalError("Token already has another parent.");

    pToken->setParent(this);
    m_vChilds.push_back(pToken);
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::remove(LanguageToken *pToken)
{
    if (pToken==NULL)
        return;

    int n = m_vChilds.indexOf(pToken);
    if (n!=-1)
    {
        m_vChilds.remove(n);
        delete pToken;
    }
}

//-------------------------------------------------------------------------------------------------
LanguageToken* LanguageToken::find(const QString &sName)
{
    for (int i=0; i<m_vChilds.size(); ++i)
    {
        if (m_vChilds[i]->getName()==sName)
            return m_vChilds[i];
    }

    return NULL;
}

void LanguageToken::addVar(const QString& sName, int nLine)
{
    if (sName.isEmpty() || sName.isNull())
        return;

    int i = sName.indexOf('.');
    if (i == sName.length() - 1)
        return;

    if (i == -1)
    {
        add(new VarDefinition(sName,  nLine));
    }
    else
    {
        QString aClass = sName.left(i);
        QString sSec = sName.mid(i + 1);

        LanguageToken* pClass = find(aClass);
        if (pClass == NULL)
        {
            add(new ClassDefinition(aClass, sSec, "", nLine));
        }
        else
            pClass->addVar(sSec, nLine);
    }
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::addFunction(const QString &sName,
                                const QString &sArg,
                                int nLine)
{
    if (sName.isEmpty() || sName.isNull())
        return;

    int i = sName.indexOf('.');
    if (i==sName.length()-1)
        return;

    if (i==-1)
    {
        add(new FunctionDefinition(sName, sArg, nLine));
    }
    else
    {
        QString aClass = sName.left(i);
        QString sSec = sName.mid(i+1);

        LanguageToken *pClass = find(aClass);
        if (pClass==NULL)
        {
            add(new ClassDefinition(aClass, sSec, sArg, nLine));
        }
        else
            pClass->addFunction(sSec, sArg, nLine);
    }
}

//-------------------------------------------------------------------------------------------------
QTreeWidgetItem* LanguageToken::toTreeItem()
{
    QTreeWidgetItem *pSelf = new QTreeWidgetItem();

    pSelf->setText(0, m_sName);
    if (m_nLine>=0)
    {
//        pSelf->setText(1, QString::number(m_nLine));
        pSelf->setTextAlignment(1, Qt::AlignCenter);
        pSelf->setData(1, Qt::DisplayRole, QVariant(m_nLine));
    }

    pSelf->setIcon(0, m_icon);

    for (int i=0; i<m_vChilds.size(); ++i)
    {
        pSelf->addChild(m_vChilds[i]->toTreeItem());
    }

    return pSelf;
}

//-------------------------------------------------------------------------------------------------
//
//
// class Script
//
//
//-------------------------------------------------------------------------------------------------

ScriptOutline::ScriptOutline(const QString &sName)
    :LanguageToken(sName)
{
    m_icon = QIcon(":/outline/res/text-x-preview.ico");
}

//-------------------------------------------------------------------------------------------------
//
//
// class LanguageToken
//
//
//-------------------------------------------------------------------------------------------------

ClassDefinition::ClassDefinition(const QString &sName,
                                 const QString &sRest,
                                 const QString &sArg,
                                 int nLine)
    :LanguageToken(sName)
{
    m_icon = QIcon(":/outline/res/code-class.ico");
    addFunction(sRest, sArg, nLine);
}

//-------------------------------------------------------------------------------------------------
//
//
// class FunctionDefinition
//
//
//-------------------------------------------------------------------------------------------------

FunctionDefinition::FunctionDefinition(const QString &sName,
                                       const QString &sArgs,
                                       int nLine)
    :LanguageToken(sName)
    ,m_sArgs(sArgs)
{
    m_icon = QIcon(":/outline/res/code-function.png");

    setLine(nLine);
}

VarDefinition::VarDefinition(const QString& sName,
    int nLine)
    :LanguageToken(sName)
{
    m_icon = QIcon(":/outline/res/code-variable.png");

    setLine(nLine);
}
