#include "chargen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CharGen w;
    w.show();

    return a.exec();
}
