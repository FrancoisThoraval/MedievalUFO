#ifndef map_hpp
#define map_hpp

#include "element.hpp"

#include "../Scenery/scenery.hpp"
#include <iostream>
#include "../Unit/unit.hpp"
const int TILESIZEX = 20;
const int TILESIZEY = 20;

class Map {
protected:
  Unit **_world1;
  Scenery **_world2;
  int _sizeX;
  int _sizeY;
  sf::Texture texture;
  sf::Sprite sprite;
public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Scenery getElementW2(Position)const;
  Unit getElementW1(Position)const;
  void setElementW1(Position,Unit);
  void setElementW2(Position,Scenery);
  std::string getNameOfElement(Position)const;
  void setElement(Position,Element);
  void drawWorld(sf::RenderWindow &);
  void createTile(int,int,sf::RenderWindow &);

};

#endif
