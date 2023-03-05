#ifndef QSELECTION_H
#define QSELECTION_H

#include <QWidget>

namespace Ui {
class QSelection;
}

class QSelection : public QWidget
{
    Q_OBJECT
    
public:
    explicit QSelection(QWidget *parent = 0);
    ~QSelection();
    
private:
    Ui::QSelection *ui;
};

#endif // QSELECTION_H
