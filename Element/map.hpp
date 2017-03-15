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
  Scenery getElement(Position)const;
  std::string getNameOfElement(Position)const;
  void setElement(Position,Element);
  void drawWorld(sf::RenderWindow &);
  void createTile(int,int,sf::RenderWindow &);

};

#endif
