#include "FrmProjectExplorer.h"
#include "ui_FrmProjectExplorer.h"

//--- Qt lib framework ----------------------------------------------------------------------------
#include <QVector>
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
//--- Luanda framework ----------------------------------------------------------------------------
#include "IFile.h"
#include "IMainFrame.h"
#include "Exceptions.h"
#include "Prototypes.h"

//-------------------------------------------------------------------------------------------------
FrmProjectExplorer::FrmProjectExplorer(IMainFrame *pWndMain)
    :QWidget(pWndMain->asWidget())
    ,ui(new Ui::FrmProjectExplorer)
    ,m_pWndMain(pWndMain)
    ,m_dirProjects()
    ,m_pScriptOutline()
    ,m_pActiveFile(NULL)
{
    ui->setupUi(this);
    ui->paCaption->setColorScheme(QGradientPanel::csBLUE);
    ui->paCaption->setCaption(tr("Explorer"));

    initOutline();
}

//-------------------------------------------------------------------------------------------------
FrmProjectExplorer::~FrmProjectExplorer()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::initOutline()
{
    QTreeWidgetItem* itHeader = new QTreeWidgetItem();
    itHeader->setText(0, "Function overview");
    itHeader->setTextAlignment(0, Qt::AlignCenter);
    itHeader->setText(1, "Line");
    itHeader->setTextAlignment(1, Qt::AlignCenter);
    ui->tvOutline->setHeaderItem(itHeader);

    ui->tvOutline->header()->setStretchLastSection(false);
    ui->tvOutline->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tvOutline->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//    ui->tvOutline->setAlternatingRowColors(true);
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::setProjectPath(QString sNewPath)
{
    m_dirProjects.setPath(sNewPath);
}

//-------------------------------------------------------------------------------------------------
const QDir& FrmProjectExplorer::getProjectPath() const
{
    return m_dirProjects;
}

//-------------------------------------------------------------------------------------------------
//
// ISettingsProvider interface
//
//-------------------------------------------------------------------------------------------------

void FrmProjectExplorer::writeSettings(QSettings &settings)
{
    settings.beginGroup("Paths");
    settings.setValue("projects", m_dirProjects.absolutePath());
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::readSettings(QSettings &settings)
{
    settings.beginGroup("Paths");
    m_dirProjects.setPath(settings.value("projects", "").toString());
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::updateFromSettings()
{}

//-------------------------------------------------------------------------------------------------
//
// IFileobserver interface
//
//-------------------------------------------------------------------------------------------------

/** \brief Aktualisieren der Outline Ansicht.
*/
void FrmProjectExplorer::notifyFileActivate(const IFile *pFile)
{
    try
    {
        if (m_pActiveFile!=pFile)
        {
            updateOutline(pFile);
        }
        m_pActiveFile = pFile;
    }
    catch(const Exception &exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.getMessage());
        msgBox.exec();
    }
    catch(...)
    {
        QMessageBox msgBox;
        msgBox.setText("Internal error in FrmProjectExplorer::notifyFileActivate");
        msgBox.exec();
    }
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileLoad(const IFile *pFile)
{
    updateOutline(pFile);
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyBeforeFileSave(IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileModified(const IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker)
{}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileLinesChanged(const IFile *pFile)
{
    updateOutline(pFile);
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyPathChanged(const IFile *pFile)
{
    updateOutline(pFile);
}

//-------------------------------------------------------------------------------------------------
//
// sonstiges
//
//-------------------------------------------------------------------------------------------------

void FrmProjectExplorer::updateOutline(const IFile *pFile)
{
    ui->tvOutline->clear();
    m_pScriptOutline.clear();

    if (pFile==NULL)
        return;

    // Heraussuchen von Funktionsdefinitionen
    const QVector<QString> &vLines = pFile->getLines();
    if (vLines.size()==0)
        return;

    QRegExp regex = QRegExp(".PROGRAM \\s*([^\\(]*)\\(([^)]*)\\)(.*)",
                            Qt::CaseSensitive,
                            QRegExp::RegExp);
    if (!regex.isValid())
        throw InternalError("Can't create outline: Invalid regular expression.");

    m_pScriptOutline = QSharedPointer<ScriptOutline>(new ScriptOutline(pFile->getName()));
    bool bVarStat = false;
    bool bStat = false;
    // Heraussuchen der Funktionsdefinitionen
    for (int i=0; i<vLines.size(); ++i)
    {
        QString sLine = vLines[i];
        bStat = regex.exactMatch(sLine);

        if (sLine.startsWith(".TRANS") || sLine.startsWith(".JOINTS") || sLine.startsWith(".STRINGS")
            || sLine.startsWith(".REALS"))
        {
            bVarStat = true;
            continue;
        }
        if (sLine.startsWith(".END"))
        {
            bVarStat = false; 
        }
        if (!bStat && !bVarStat)
           continue;

        if (bStat)
        {
            int nCount = regex.captureCount();
            if (nCount < 3)
                continue;

            // Die Zeile enthält eine gültige Funktionsdefinition
            QString sMatch = regex.cap(0);
            QString sFunName = regex.cap(1);
            QString sFunArgs = regex.cap(2);

            // aktualisieren der Outline, mit einsbasierten indizes
            m_pScriptOutline->addFunction(sFunName, sFunArgs, i + 1);

            qDebug() << "function " << sFunName << "(" << sFunArgs << ")";
        }      
      
        if (bVarStat)
        {
            QStringList strList = sLine.split(" ");
            if (strList.count() > 1 && !strList.at(0).startsWith(";"))
            {
                m_pScriptOutline->addVar(strList.at(0), i + 1);
                qDebug() << "var " << strList.at(0);
            }
        }
    }

    QTreeWidgetItem *pOutline = m_pScriptOutline->toTreeItem();
    ui->tvOutline->invisibleRootItem()->addChild(pOutline);
    ui->tvOutline->expandAll();
}

void FrmProjectExplorer::Reset()
{
    QTreeWidgetItem* pOutline = m_pScriptOutline->toTreeItem();
    if (pOutline)
    {
        ui->tvOutline->invisibleRootItem()->removeChild(pOutline);
        delete pOutline;
        pOutline = NULL;
  
        
    }
    ui->tvOutline->clear();
}
//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::on_tvOutline_itemSelectionChanged()
{
    if (m_pActiveFile==NULL)
        return;

    QList<QTreeWidgetItem *> items = ui->tvOutline->selectedItems();
    if (items.size()>0)
    {
        QVariant data = items[0]->data(1, Qt::DisplayRole);
        if (data.isValid())
        {
            m_pActiveFile->navigateToLine(data.toInt(), tmHIGHLIGHT);
        }
    }
}
