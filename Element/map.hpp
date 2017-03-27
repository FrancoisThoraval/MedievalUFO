#ifndef map_hpp
#define map_hpp

// #include "element.hpp"
#include "../Unit/unit.hpp"
#include "../Scenery/scenery.hpp"
#include "../Game/menu.hpp"
#include "../Player/player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <sys/time.h>

const int TILESIZEX = 32;
const int TILESIZEY = 32;

class Unit;

class Map {
protected:
  Unit **_world1;
  Scenery **_world2;
  int _sizeX;
  int _sizeY;
  sf::Sprite **_mapTile;
  int _tileClicked;
  Unit *_tabUnit;
  int _compttab;
  Position _unitSelected;
public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Scenery getElementW2(Position)const;
  Unit getElementW1(Position)const;
  void setElementW1(Position,Unit&);
  void setElementW2(Position,Scenery&);
  std::string getNameOfElement(Position)const;
  void setElement(Position,Element*);
  void drawWorld(sf::RenderWindow &);
  void createTile(int,int,sf::RenderWindow &,sf::Texture &);
  bool isOnMap(Position pos);

  void handleClick(sf::RenderWindow &, sf::Event &,Player&);

  int getSizeX();
  int getSizeY();
  int getCompt()const;
  Unit getTab(int)const;
  void setSizeX(int);
  void setSizeY(int);
  void setCompt(int);
  void setInTab(Unit&&);

};


class Ui {
private:

public:
     Ui ();
     ~Ui ();
     void drawUi(sf::RenderWindow &);
     void handleClick(sf::RenderWindow &,sf::Event &);
     void displayInfoPlayer(sf::RenderWindow &, Player &);
};

#endif
