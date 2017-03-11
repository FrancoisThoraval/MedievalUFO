#include <QApplication>
#include <QWidget>

#include "Element/map.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map m(15,15);

    m.drawWorld();

    return app.exec();
}
