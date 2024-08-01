#include "widget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();
    QObject::connect(qApp, &QApplication::lastWindowClosed, &a, &QApplication::quit);
    return a.exec();
}
