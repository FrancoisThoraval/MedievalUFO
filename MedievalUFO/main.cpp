#include <QApplication>
#include <QWidget>

#include "Element/map.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map m(32,32);
    m.drawWorld();
    Position pos;
    pos.setX(5);
    pos.setY(5);
    std::cout<<m.getNameOfElement(pos)<<std::endl;
    return app.exec();
}
