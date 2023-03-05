#ifndef IFILE_H
#define IFILE_H


//--- Qtlib includes ------------------------------------------------------------------------------
#include <QString>
#include <QSharedPointer>
#include <QFileInfo>
#include <QVector>

//-------------------------------------------------------------------------------------------------
#include "IProject.h"
#include "IFileObserver.h"
#include "IObserveable.h"
#include "ILockable.h"

//-------------------------------------------------------------------------------------------------
/** \brief Interface für Dateien, die in Luanda angezeigt werden können.
*/
class IFile : public IObserveable<IFileObserver>,
              public ILockable
{
public:

    typedef QSharedPointer<IFile> ptr_type;

    IFile();
    virtual ~IFile();

    virtual std::size_t getNumLines() const = 0;
    virtual const QString& getLine(std::size_t i) const = 0;
    virtual const QVector<QString>& getLines() const = 0;
    virtual void addLine(const QString &sLine) = 0;
    virtual void clear() = 0;

    virtual QString getName() const = 0;
    virtual IProject* getProject() = 0;
    virtual const QFileInfo* getFileInfo() const = 0;

    virtual QString getPath() const = 0;

    void activate() const;
    void load();
    void save();
    void updateOutline() const;
    void navigateToLine(int nLine, ETextMarker eMarker) const;
    void setPath(const QString &sPath);

    bool wasModified() const;
    void setModified(bool bStat)        ;
    void setObserver(IFileObserver *pObs);

protected:
    virtual void loadImpl() = 0;
    virtual void saveImpl() = 0;
    virtual void setPathImpl(const QString &sNewPath) = 0;

private:
    QVector<IFileObserver*>  m_vObserver;
    bool m_bModified;
};

#endif // IFILE_H
