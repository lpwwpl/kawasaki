#include "FrmFindReplace.h"
#include "ui_FrmFindReplace.h"

#include "Settings.h"
#include "Exceptions.h"


FrmFindReplace::FrmFindReplace(QWidget* parent ): ui(new Ui::FrmFindReplace)
{
	ui->setupUi(this);
}
FrmFindReplace::~FrmFindReplace()
{

}
