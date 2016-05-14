#include "taiko.h"
#include "play.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));
    Taiko w;
    w.setFixedSize(640, 361);
    w.show();

    return a.exec();
}
