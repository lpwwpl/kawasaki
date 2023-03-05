#include "FileLua.h"

//--- Standard includes ---------------------------------------------------------------------------
#include <stdexcept>

//--- QTlib includes ------------------------------------------------------------------------------
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDir>
#include <QDebug>


//-------------------------------------------------------------------------------------------------
IFile::ptr_type FileLua::create(const QString &sPath)
{
    return IFile::ptr_type(new FileLua(sPath));
}

//-------------------------------------------------------------------------------------------------
FileLua::FileLua(const QString &path)
    :m_vLines()
    ,m_fi(path)
    ,m_mtxFile()
{}

//-------------------------------------------------------------------------------------------------
FileLua::~FileLua()
{}

//-------------------------------------------------------------------------------------------------
QString FileLua::getPath() const
{
    return m_fi.absoluteFilePath();
}

//-------------------------------------------------------------------------------------------------
QString FileLua::getName() const
{
    return m_fi.fileName();
}

//-------------------------------------------------------------------------------------------------
std::size_t FileLua::getNumLines() const
{
    return m_vLines.size();
}

//-------------------------------------------------------------------------------------------------
/** \brief Löscht den zwischengepufferten Dateiinhalt.
*/
void FileLua::clear()
{
    m_vLines.clear();
}

//-------------------------------------------------------------------------------------------------
void FileLua::addLine(const QString &sLine)
{
    m_vLines.push_back(sLine);
}

//-------------------------------------------------------------------------------------------------
const QString& FileLua::getLine(std::size_t i) const
{
    return m_vLines.at(i);
}

//-------------------------------------------------------------------------------------------------
const QVector<QString>& FileLua::getLines() const
{
    return m_vLines;
}

//-------------------------------------------------------------------------------------------------
IProject* FileLua::getProject()
{
    return NULL;
}

//-------------------------------------------------------------------------------------------------
const QFileInfo* FileLua::getFileInfo() const
{
    return &m_fi;
}

//-------------------------------------------------------------------------------------------------
void FileLua::loadImpl()
{
    m_vLines.clear();

    QFile file( m_fi.filePath());
    if ( file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        QTextStream stream( &file );
        while ( !stream.atEnd() )
        {
            m_vLines.push_back(stream.readLine());
        }
        file.close();
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Abspeichern der Datei. */
void FileLua::saveImpl()
{
    if (!m_fi.absoluteDir().exists())
    {
        qDebug() << "creating path: " << m_fi.absolutePath();
        QDir().mkpath(m_fi.absolutePath());
    }

    QFile file(m_fi.filePath());
    if ( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
        throw std::runtime_error("Can't save file");

    QTextStream stream(&file);
    for (int i=0; i<m_vLines.size(); ++i)
    {
        QString sLine = m_vLines[i];
        stream << m_vLines[i]; //sLine;
    }
    file.close();
}

//-------------------------------------------------------------------------------------------------
void FileLua::setPathImpl(const QString &sPath)
{
    m_fi.setFile(sPath);
}

//-------------------------------------------------------------------------------------------------
void FileLua::lock() const
{
    m_mtxFile.lock();
}

//-------------------------------------------------------------------------------------------------
void FileLua::unlock() const
{
    m_mtxFile.unlock();
}
