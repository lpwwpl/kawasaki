#ifndef FRMCONSOLE_H
#define FRMCONSOLE_H

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QWidget>
#include <QVector>

//-------------------------------------------------------------------------------------------------
#include "FwdDecl.h"
#include "QCommandPrompt.h"
#include "ISettingsProvider.h"


namespace Ui {
    class FrmConsole;
}

class FrmConsole : public QWidget,
                   public ISettingsProvider
{
    Q_OBJECT

public:

    enum ELineOptions
    {
        loNORMAL,
        loWITHOUT_PROMPT
    };

    explicit FrmConsole(QWidget *parent = 0);
    virtual ~FrmConsole();

    //void bindToInterpreter(IInterpreter *pInterpreter);

    // ISettingsProvider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

    IConsole* getIConsole();
    QCommandPrompt* getConsole();

private:
    Ui::FrmConsole *ui;
};

#endif // FRMDEBUG_H
