#include "cr3_train.h"
#include "ui_cr3_train.h"

CR3_Train::CR3_Train(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CR3_Train)
{
    ui->setupUi(this);

    setWindowTitle("지역 선택");
}

CR3_Train::~CR3_Train()
{
    delete ui;
}
