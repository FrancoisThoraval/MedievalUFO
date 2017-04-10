#ifndef unit_hpp
#define unit_hpp

#include "../Element/map.hpp"
//#include "./zedd.hpp"
#include "../Element/element.hpp"
#include "../Player/player.hpp"
#include "weapon.hpp"
// #include "ayayay.hpp"
#include <string>

/***** Classe des unités, class mères de tous les types d'unites ********/
class Unit;
class Putties;
class PowerRanger;
// class AYAYAY_Assistant;
class RobotPR;
class TurtleTank;
class Zedd;

class Map;


class Unit : public Element {
private:
  std::string _name;
  int _healthPoints;
  int _price;
  int _movement;
protected:
  int _defaultMovement;
  Weapon *_primaryWeapon;
  Weapon *_secondaryWeapon;
  Weapon *_thirdWeapon;
  Weapon *_fourthWeapon;
public:
  Unit ();
  ~Unit ();
  Unit(Unit&);
  std::string getName()const;
  /** Getter **/
  int getHealthPoints()const;
  int getPrice()const;
  int getMovement()const;
  Weapon* getPrimaryW()const;
  Weapon* getSecondaryW()const;
  Weapon* getThirdW()const;
  Weapon* getFourthW()const;
  int getDefault()const;
  void setDefault(int);
  /** Setter **/
  void setName(std::string);
  void setHealthPoints(int);
  void setPrice(int);
  void setMovement(int);
  void setPrimaryW(Weapon*);
  void setSecondaryW(Weapon*);
  void setThirdW(Weapon*);
  void setFourthW(Weapon*);
  /** Methode **/
  void attack(Unit&,int,Player&,Player&,Position,Map*);
  void move(Position,Position,Map*,int,Player&,Player&);
  friend class Weapon;
  Unit& operator=(Unit& u){
    this->_name = u._name;
    this->_healthPoints = u._healthPoints;
    this->_price = u._price;
    this->_movement = u._movement;
    this->setPosition(u.getPosition());
    return(*this);
  }

  //Unit& operator=( PowerRanger&);
  //   this->_name = pr._name;
  //   this->_healthPoints = pr._healthPoints;
  //   this->_price = pr._price;
  //   this->_movement = pr._movement;
  //   this->_defaultMovement = pr._defaultMovement;
  //   return(*this);
  // }




};

class Zedd : public Unit{
private:
  bool _activeExpendNade;
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;
  bool apoon;


public:
  Zedd ();
  ~Zedd ();
  int getActiveExpendNade()const;
  int getInvocation()const;
  int getPuttiesCalling()const;
  int getApocalypseHole()const;
  bool getApoon()const;
  void setApoon(bool);

  void setActiceExpendNade(int);
  void setInvocation(int);
  void setPuttiesCalling(int);
  void setApocalypseHole(int);

  void ThrowExtendNade(Position,Map*,Player&);
  void EnableGrenade(Map);
  void Invocation(Position,Map*,Player&);
  void PuttiesCalling(Position,Map*,Player&);
  void ApocalypseHole(Map*,Player&);
  Zedd& operator=(const Unit& u){
    this->setName(u.getName());
    this->setHealthPoints(u.getHealthPoints());
    this->setPrice(u.getPrice());
    this->setMovement(u.getMovement());
    this->setPrimaryW(u.getPrimaryW());
    this->setSecondaryW(u.getSecondaryW());
    this->setThirdW(u.getThirdW());
    this->setFourthW(u.getFourthW());
    this->setDefault(u.getDefault());
    return(*this);
  }
};


/** le fantassin est une unité de base qui n'as rien de special ... il est nul **/

class Putties : public Unit {
private:

public:
  Putties ();
  ~Putties ();
  Putties(int,int,int,Weapon*,std::string= "Putties"); //hp,mvmt,price,arme
  void attack(Unit&,int,Player&,Position);
  Putties& operator=(const Unit& u){
    this->setName(u.getName());
    this->setHealthPoints(u.getHealthPoints());
    this->setPrice(u.getPrice());
    this->setMovement(u.getMovement());
    this->setPrimaryW(u.getPrimaryW());
    this->setDefault(u.getDefault());
    return(*this);
  }
};

class PowerRanger : public Unit {
private:
  std::string _color;
  bool _capacityRobot;
  bool _capacityWeapon;


public:
  PowerRanger ();
  PowerRanger (std::string);
  ~PowerRanger();
  void setColor(std::string);
  std::string getColor()const;
  void setCapacityRobot(bool);
  void setCapacityWeapon(bool);
  bool getCapacityRobot()const;
  bool getCapacityWeapon()const;
  int getDefault()const;
  void TornadoDino(Map*,Position);
  //void attack(Unit &, int,Player&,Map *m,Position);
  void BeTogether(Map*,Position,bool*,bool*);
  void Transformation(Map*);
  void CheaterWeaponOn(Map*);
  PowerRanger& operator=(const Unit& u){
    this->setName(u.getName());
    this->setHealthPoints(u.getHealthPoints());
    this->setPrice(u.getPrice());
    this->setPosition(u.getPosition());
    this->setMovement(u.getMovement());
    this->setPrimaryW(u.getPrimaryW());
    this->setSecondaryW(u.getSecondaryW());
    this->setThirdW(u.getThirdW());
    this->setFourthW(u.getFourthW());
    this->setDefault(u.getDefault());
    return(*this);
  }

};


class Dino : public Unit {
private:

public:
  Dino ();
  ~Dino ();
};


// class AYAYAY_Assistant : public Unit{
// private:
//   std::string _advice;
// public:
//  AYAYAY_Assistant ();
//  ~AYAYAY_Assistant ();
//  void setAdvice(std::string);
//  std::string getAdvice()const;
//
//
// };
/*
class Zedd : public Unit{
private:
  bool _activeExpendNade;
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;
  Weapon* _thirdWeapon;
  Weapon* _fourthWeapon;

public:
  Zedd ();
  virtual ~Zedd ();
  int getActiveExpendNade()const;
  int getInvocation()const;
  int getPuttiesCalling()const;
  int getApocalypseHole()const;

  void setActiceExpendNade(int);
  void setInvocation(int);
  void setPuttiesCalling(int);
  void setApocalypseHole(int);

  void ThrowExtendNade(Position);
  void Invocation(Position,Map &);
  //void PuttiesCalling(Position);
  //void ApocalypseHole();
};
*/
class RobotPR : public Unit {
private:
  int _armor;

public:
  RobotPR ();
  virtual ~RobotPR ();
  int getArmor()const;
  void setArmor(int);
  //void attack(Unit&, int,Player&, Position );
  RobotPR& operator=(const Unit& u){
    this->setName(u.getName());
    this->setHealthPoints(u.getHealthPoints());
    this->setPrice(u.getPrice());
    this->setMovement(u.getMovement());
    this->setPrimaryW(u.getPrimaryW());
    this->setSecondaryW(u.getSecondaryW());
    this->setDefault(u.getDefault());
    return(*this);
  }
};

class TurtleTank : public RobotPR {
private:

public:
  TurtleTank ();
  virtual ~TurtleTank ();
  //void attack(Unit&,int,Player&,Position);
  TurtleTank& operator=(const Unit& u){
    this->setName(u.getName());
    this->setHealthPoints(u.getHealthPoints());
    this->setPrice(u.getPrice());
    this->setMovement(u.getMovement());
    this->setPrimaryW(u.getPrimaryW());
    this->setDefault(u.getDefault());
    return(*this);
  }

};

/* l'archer est une unité qui peut tirer a distance et changer de type de fleches pour faire plus mal

class Archer : public Unit {
private:
int _changeArrowTime;
int _typeOfArrow;
public:
Archer ();
~Archer ();
void setOnFire();
void setOnDefault();
int getTypeOfArrow()const;
int getChangeOfTime()const;
void setChangeOnTime(int);
void attack(Unit&);
};

 le cavalier est une unité qui peut se deplacer sur plusieur cases

class Cavalier : public Unit {
private:

public:
Cavalier ();
~Cavalier ();
void attack(Unit&);

};

 la catapulte est une unité qui peut faire de gros dommages a moyennes distances en zone

class Catapulte : public Unit {
private:
int _reloadTime;
public:
Catapulte ();
~Catapulte ();
int getReloadTime()const;
void setReloadTime(int);
void attack(Unit&);
};
*/
#endif
