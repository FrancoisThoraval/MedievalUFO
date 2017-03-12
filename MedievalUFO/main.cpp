#include <QApplication>
#include <QWidget>

#include "Element/map.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map m(32,32);

    m.drawWorld();

    return app.exec();
}
