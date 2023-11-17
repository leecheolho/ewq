#include "cr3_user.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CR3_User w;
    w.show();
    return a.exec();
}
