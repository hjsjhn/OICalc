#include "calc.h"

#include <QApplication>

int main (int argc, char *argv[]) {
    QApplication a(argc, argv);
    calc app;
    app.show();
    return a.exec();
}
