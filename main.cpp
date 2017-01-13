#include "softtop.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoftTop w;
    w.show();

    return a.exec();
}
