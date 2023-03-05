#include "FrmConsole.h"
#include "ui_FrmConsole.h"

#include "Settings.h"
#include "Exceptions.h"


//-------------------------------------------------------------------------------------------------
FrmConsole::FrmConsole(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::FrmConsole)
{
    ui->setupUi(this);

    ui->edConsole->setPrompt("As", ">");
    ui->paCaption->setCaption("Console");
    ui->paCaption->setColorScheme(QGradientPanel::csBLUE);
}

//-------------------------------------------------------------------------------------------------
FrmConsole::~FrmConsole()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmConsole::writeSettings(QSettings & /*settings*/)
{}

//-------------------------------------------------------------------------------------------------
void FrmConsole::readSettings(QSettings & /*settings*/)
{}

//-------------------------------------------------------------------------------------------------
void FrmConsole::updateFromSettings()
{
    const Settings &settings = Settings::Instance();
    ui->edConsole->setFontSize(settings.getFontSize());
}

//-------------------------------------------------------------------------------------------------
IConsole* FrmConsole::getIConsole()
{
    return ui->edConsole;
}

//-------------------------------------------------------------------------------------------------
QCommandPrompt* FrmConsole::getConsole()
{
    return ui->edConsole;
}



