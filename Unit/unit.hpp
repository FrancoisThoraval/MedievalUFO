#ifndef unit_hpp
#define unit_hpp

#include "../Element/element.hpp"
#include "../Element/map.hpp"
#include "weapon.hpp"
#include <string>

/***** Classe des unités, class mères de tous les types d'unites ********/
// class Unit;
class Putties;
class PowerRanger;
class AYAYAY_Assistant;
class RobotPR;
class TurtleTank;
class Map;
//class Archer;
//class Cavalier;
//class Catapulte;

class Unit : public Element {
private:
  std::string _name;
  int _healthPoints;
  int _price;
  int _movement;
protected:
  Weapon *_primaryWeapon;
  Weapon *_secondaryWeapon;
public:
  Unit ();
  virtual ~Unit ();
  std::string getName()const;
  /** Getter **/
  int getHealthPoints()const;
  int getPrice()const;
  int getMovement()const;
  Weapon* getPrimaryW()const;
  Weapon* getSecondaryW()const;
  /** Setter **/
  void setName(std::string);
  void setHealthPoints(int);
  void setPrice(int);
  void setMovement(int);
  void setPrimaryW(Weapon*);
  void setSecondaryW(Weapon*);
  /** Methode **/
  virtual void attack();
  virtual void move();
  friend class Weapon;

};

/** le fantassin est une unité de base qui n'as rien de special ... il est nul **/

class Putties : public Unit {
private:

public:
  Putties ();
  ~Putties ();
  Putties(int,int,Weapon*);
  void attack(Unit&,int);
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

  void attack(Unit &, int);
};

class AYAYAY_Assistant : public Unit{
private:
  std::string _advice;

public:
 AYAYAY_Assistant ();
 ~AYAYAY_Assistant ();
 void setAdvice(std::string);
 std::string getAdvice()const;

};

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

class RobotPR : public Unit {
private:
  int _armor;

public:
  RobotPR ();
  virtual ~RobotPR ();
  int getArmor()const;
  void setArmor(int);
  void attack(Unit&, int );
};

class TurtleTank : public RobotPR {
private:

public:
  TurtleTank ();
  virtual ~TurtleTank ();
  void attack(Unit& u);

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
