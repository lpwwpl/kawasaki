#include "IFile.h"
#include <QString>

//-------------------------------------------------------------------------------------------------
IFile::IFile()
    :m_vObserver()
    ,m_bModified(false)
{}

//-------------------------------------------------------------------------------------------------
IFile::~IFile()
{}

//-------------------------------------------------------------------------------------------------
void IFile::setModified(bool bStat)
{
    if (!hasObservers())
        return;

    m_bModified = bStat;

//    if (bOld!=m_bModified)
    {
        // Meldung über Änderung am File an alle Observer absetzen
        obs_list::iterator it = m_observer.begin();
        for (; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileModified(this);
        }
    }
}

//-------------------------------------------------------------------------------------------------
bool IFile::wasModified() const
{
    return m_bModified;
}

//-------------------------------------------------------------------------------------------------
void IFile::activate() const
{
    if (!hasObservers())
        return;

    obs_list::const_iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyFileActivate(this);
    }
}

//-------------------------------------------------------------------------------------------------
void IFile::updateOutline() const
{
    if (!hasObservers())
        return;

    obs_list::const_iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyFileLinesChanged(this);
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Anzeigen und gegebenenfalls markieren einer bestimmten Zeile.
*/
void IFile::navigateToLine(int nLine, ETextMarker eMarker) const
{
    if (!hasObservers())
        return;

    obs_list::const_iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyFileLineSelected(this, nLine, eMarker);
    }
}

//-------------------------------------------------------------------------------------------------
void IFile::load()
{
    loadImpl();

    if (hasObservers())
    {
        obs_list::iterator it = m_observer.begin();
        for ( ; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileLoad(this);
        }
    }

    m_bModified = false;
}

//-------------------------------------------------------------------------------------------------
void IFile::save()
{
    obs_list::iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyBeforeFileSave(this);
    }

    saveImpl();
    m_bModified = false;
}

//-------------------------------------------------------------------------------------------------
void IFile::setPath(const QString &sNewPath)
{
    setPathImpl(sNewPath);

    obs_list::iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyPathChanged(this);
    }
}



