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
  int _value;
public:
  Player();
  Player (std::string,int);
  ~Player ();

  int getValue()const;
  int getEnergy()const;
  bool getLost()const;
  std::string getName()const;

  void setValue(int);
  void setEnergy(int);
  void setLost(bool);
  void setName(std::string);

  void pushUnit(Unit &);
  void showUnitOwned();
  //void EndOfTurn(Map*);
};

#endif
