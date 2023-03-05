#include "QSelection.h"
#include "ui_QSelection.h"

QSelection::QSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSelection)
{
    ui->setupUi(this);
}

QSelection::~QSelection()
{
    delete ui;
}
