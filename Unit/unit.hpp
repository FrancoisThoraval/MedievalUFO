#ifndef unit_hpp
#define unit_hpp

#include "../Element/element.hpp"
#include <string>

/***** Classe des unités, class mères de tous les types d'unites ********/
class Unit;
class Putties;
class PowerRanger;
class AYAYAY_Assistant;
class Zedd;
class RobotPR;
//class Archer;
//class Cavalier;
//class Catapulte;

class Unit : public Element {
private:
  std::string _name;
  int _strengh;
  int _attackRange;
  int _healthPoints;
  int _price;
  int _energyCost;
public:
  Unit ();
  virtual ~Unit ();
  std::string getName()const;
  /** Getter **/
  int getStrengh()const;
  int getAttackRange()const;
  int getHealthPoints()const;
  int getPrice()const;
  int getEnergyCost()const;
  /** Setter **/
  void setName(std::string);
  void setStrengh(int);
  void setAttackRange(int);
  void setHealthPoints(int);
  void setPrice(int);
  void setEnergyCost(int);
  /** Methode **/
  virtual void attack();
  virtual void move();

};

/** le fantassin est une unité de base qui n'as rien de special ... il est nul **/

class Putties : public Unit {
private:

public:
  Putties ();
  ~Putties ();
  void attack(Unit&);
};

/** l'archer est une unité qui peut tirer a distance et changer de type de fleches pour faire plus mal **/
/*
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

/** le cavalier est une unité qui peut se deplacer sur plusieur cases **/
/*
class Cavalier : public Unit {
private:

public:
  Cavalier ();
  ~Cavalier ();
  void attack(Unit&);

};

/** la catapulte est une unité qui peut faire de gros dommages a moyennes distances en zone **/
/*
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

// definir la class Unité cheater du milieu
*/

class PowerRanger : public Unit {
private:
  std::string _color;
  bool _capacityRobot;
  bool _capacityWeapon;

public:
  PowerRanger ();
  ~PowerRanger();
  void setColor(string);
  string getColor()const;
  void setCapacityRobot(bool);
  void setCapacityWeapon(bool);
  bool getCapacityRobot()const;
  bool getCapacityWeapon()const;
};

class AYAYAY_Assistant : public Unit{
private:
  std::string _advice;

public:
 AYAYAY_Assistant ();
 AYAYAY_Assistant ();
 void setAdvice(std::string);
 std::string getAdvice()const;

};


class Zedd : public Unit{
private:
  int _activeExpendNade;
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;

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
};


class RobotPR : public Unit {
private:
  int _armor;

public:
  RobotPR ();
  virtual ~RobotPR ();
  int getArmor()const;
  void setArmor(int);
};


#endif
