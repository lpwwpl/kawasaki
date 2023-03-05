#ifndef PROJECTLUA_H
#define PROJECTLUA_H

//-------------------------------------------------------------------------------------------------
#include <QVector>
#include <QDir>
//#include <QtXml/QDomDocument>

//-------------------------------------------------------------------------------------------------
#include "IProject.h"
#include "FwdDecl.h"

//-------------------------------------------------------------------------------------------------
/** \brief Encapsulation of a lua project. */
class ProjectLua : public IProject
{
public:
    ProjectLua(const QString &sName);
    virtual ~ProjectLua();

    void importFromDirectory(QDir initialDir);
    void loadFromFile(const QString &sFileName);

    // IProject implementation
    virtual void addFile(const QString &sFileName);
    virtual void deleteFile(const QString &sFileName);
    virtual void open(const QString &sProject);
    virtual QString getName() const;

private:
    QString m_sProjectFile;
    QVector<FileLua*> m_vFiles;
//    QDomDocument m_xmlDoc;          ///< Projektfile als xml

    void scanDir(QDir dir);
};

#endif // PROJECTLUA_H
