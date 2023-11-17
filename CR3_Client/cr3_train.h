#ifndef CR3_TRAIN_H
#define CR3_TRAIN_H

#include <QDialog>
#include "cr3_user.h"
#include <QApplication>
#include <QPropertyAnimation>

namespace Ui {
class CR3_Train;
}

class CR3_Train : public QDialog
{
    Q_OBJECT

public:
    explicit CR3_Train(QWidget *parent = nullptr);
    ~CR3_Train();

private:
    Ui::CR3_Train *ui;
};



#endif // CR3_TRAIN_H
