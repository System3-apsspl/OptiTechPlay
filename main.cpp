#include "OptiTechPlay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OptiTechPlay w;
    w.show();

    return a.exec();
}
