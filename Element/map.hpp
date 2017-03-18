#ifndef map_hpp
#define map_hpp

#include "element.hpp"

#include "../Scenery/scenery.hpp"
#include <iostream>
// #include "../Unit/unit.hpp"
const int TILESIZEX = 32;
const int TILESIZEY = 32;

class Map {
protected:
  // Unit **_world1;
  Scenery **_world2;
  int _sizeX;
  int _sizeY;
public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Scenery getElement(Position)const;
  std::string getNameOfElement(Position)const;
  void setElement(Position,Element);
  void drawWorld(sf::RenderWindow &);
  void createTile(int,int,sf::RenderWindow &,sf::Texture);

};

#endif
