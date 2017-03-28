#ifndef player_hpp
#define player_hpp

// #include "../Element/map.hpp"
#include "../Unit/unit.hpp"
#include <iostream>
#include <string>

class Unit;

class Player {
private:
  int _energy;
  bool  _lost;
  std::string _name;
  Unit *_ownUnit;
public:
  Player();
  Player (std::string);
  ~Player ();

  int getEnergy()const;
  bool getLost()const;
  std::string getName()const;

  void setEnergy(int);
  void setLost(bool);
  void setName(std::string);

  void pushUnit(Unit &);
  void showUnitOwned();
  //void EndOfTurn(Map*);
};

#endif
