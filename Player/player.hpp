#ifndef player_hpp
#define player_hpp

//#include "../Element/map.hpp"
#include "../Unit/unit.hpp"
#include <iostream>
#include <string>

class Unit;
class Map;

class Player {                                              // CLASSE DES JOUEURS
private:                                                    //	Elle contient son nom, son energy, un tableau pour ranger les unités
 												//	la taille et la taille max de ce tableaux et si le joueurs est entrain
												//	de jouer en ce moment
  int _energy;
  bool  _lost;
  std::string _name;
  Unit **_ownUnit;
  int _sizeOwnUnit;
  bool _isPlaying;
  int _sizeOwnMax;
public:
  Player();
  Player (std::string,bool);
  ~Player ();
  /**GETTER**/
  bool getWhosPlaying()const;
  int getEnergy()const;
  bool getLost()const;
  std::string getName()const;
  bool isMineUnit(const Unit);
  bool isMineUnit(const std::string);
  Unit* getUnit(int);
  int getSizeOwnUnit()const;

  /** SETTER **/
  void setWhosPlaying(bool);
  void setEnergy(int);
  void setLost(bool);
  void setName(std::string);

  /**METHODE**/
  void pushUnit(Unit *);
  void removeUnit(Unit &);
  void showUnitOwned();
  void EndOfTurn(Map*);
  void ResetMovement(Map*);

  void hasLost();
};

#endif
