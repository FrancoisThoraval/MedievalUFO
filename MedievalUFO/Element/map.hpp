#ifndef carte_hpp
#define carte_hpp

#include "element.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../Scenery/scenery.hpp"

const int TILESIZEX = 20;
const int TILESIZEY = 20;

class Map {
private:
  Element **_world1;
  Element **_world2;
  int _sizeX;
  int _sizeY;

public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Element getElement(Position);
  void setElement(Position,Element);
  void drawWorld();
  void createTile(int,int);

};

#endif
