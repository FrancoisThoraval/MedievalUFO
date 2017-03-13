#ifndef carte_hpp
#define carte_hpp

#include "element.hpp"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "../Scenery/scenery.hpp"
#include <iostream>

const int TILESIZEX = 20;
const int TILESIZEY = 20;

class Map {
private:
  Element ***_world1;
  Scenery ***_world2;
  int _sizeX;
  int _sizeY;
  QGraphicsScene *_scene;
  QGraphicsView *_view;
public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Element getElement(Position)const;
  std::string getNameOfElement(Position)const;
  void setElement(Position,Element);
  void drawWorld();
  void createTile(int,int);

};

#endif
