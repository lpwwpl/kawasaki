#ifndef FRMFINDREPLACE_H
#define FRMFINDREPLACE_H

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QWidget>
#include <QVector>

//-------------------------------------------------------------------------------------------------
#include "FwdDecl.h"
#include "ui_FrmFindReplace.h"


namespace Ui {
    class FrmFindReplace;
}

class FrmFindReplace : public QWidget
{
    Q_OBJECT

public:

    explicit FrmFindReplace(QWidget *parent = 0);
    virtual ~FrmFindReplace();

public:
    Ui::FrmFindReplace* ui;
};

#endif // FRMDEBUG_H
