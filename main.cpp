#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Win7 w(0);
    w.show();
    Win8 win(0);
    win.show();
    Win9 window;
    window.show();
    return a.exec();
}
