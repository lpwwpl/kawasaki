#include "ProjectLua.h"
#include "FileLua.h"

#include <QDirIterator>
#include <QFileInfo>

#include "Exceptions.h"


//-------------------------------------------------------------------------------------------------
ProjectLua::ProjectLua(const QString &sName)
    :m_sProjectFile()
    ,m_vFiles()
{
    // Herausfinden ob sName ein Directoryname oder ein Projektfilename ist
    QFileInfo fileInfo(sName);

    if (!fileInfo.exists())
        throw FileIOException(QString("File or directory \"%1\" does not exist").arg(sName));

    if (fileInfo.isDir())
    {
        importFromDirectory(fileInfo.dir());
    }
    else if (fileInfo.isFile())
    {
        QString sFileName = fileInfo.fileName();
        if (sFileName.endsWith(".luaprj"))
        {
            loadFromFile(fileInfo.fileName());
        }
    }

}

//-------------------------------------------------------------------------------------------------
ProjectLua::~ProjectLua()
{}

//-------------------------------------------------------------------------------------------------
void ProjectLua::loadFromFile(const QString & /*sFileName*/)
{
}

//-------------------------------------------------------------------------------------------------
void ProjectLua::importFromDirectory(QDir initialDir)
{
    scanDir(initialDir);
}

//-------------------------------------------------------------------------------------------------
void ProjectLua::scanDir(QDir dir)
{
   QDirIterator iterator(dir.absolutePath(), QDirIterator::Subdirectories);
   while (iterator.hasNext())
   {
      iterator.next();
      if (!iterator.fileInfo().isDir())
      {
         QString filename = iterator.fileName();
         if (filename.endsWith(".as"))
         {
            qDebug("Found %s matching pattern.", qPrintable(filename));
         }
      }
   }
}


//-------------------------------------------------------------------------------------------------
void ProjectLua::addFile(const QString & /*sFileName*/)
{}

//-------------------------------------------------------------------------------------------------
void ProjectLua::deleteFile(const QString & /*sFileName*/)
{}

//-------------------------------------------------------------------------------------------------
void ProjectLua::open(const QString & /*sProject*/)
{}

//-------------------------------------------------------------------------------------------------
/** \brief Erzeugt ein Projektfile durch rekursives scannen eines Verzeichnisses. */
void importFromDirectory(QString /*sPath*/)
{
}

//-------------------------------------------------------------------------------------------------
QString ProjectLua::getName() const
{
    return "";
}
