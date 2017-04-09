#ifndef player_hpp
#define player_hpp

//#include "../Element/map.hpp"
#include "../Unit/unit.hpp"
#include <iostream>
#include <string>

class Unit;
class Map;

class Player {
private:
  int _energy;
  bool  _lost;
  std::string _name;
  Unit *_ownUnit;
  int _sizeOwnUnit;
  bool _isPlaying;
public:
  Player();
  Player (std::string,bool);
  ~Player ();

  bool getWhosPlaying()const;
  int getEnergy()const;
  bool getLost()const;
  std::string getName()const;
  bool isMineUnit(const Unit);
  bool isMineUnit(const std::string);
  Unit& getUnit(int);


  void setWhosPlaying(bool);
  void setEnergy(int);
  void setLost(bool);
  void setName(std::string);

  void pushUnit(Unit &);
  void removeUnit(Unit &);
  void showUnitOwned();
  void EndOfTurn(Map*);
  void ResetMovement(Map*);

  void hasLost();
};

#endif
