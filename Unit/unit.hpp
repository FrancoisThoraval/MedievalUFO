#ifndef unit_hpp
#define unit_hpp

#include "../Element/map.hpp"
#include "../Element/element.hpp"
#include "../Player/player.hpp"
#include "weapon.hpp"
#include <string>
// #include "ayayay.hpp"
//#include "./zedd.hpp"

/***** Classe des unités, class mères de tous les types d'unites ********/
class Unit;
class Putties;
class PowerRanger;
class RobotPR;
class TurtleTank;
class Zedd;
class Map;

// class AYAYAY_Assistant;


class Unit : public Element {             // Class UNIT, class mere des unité
private:
  std::string _name;                     // nom de l'unité
  int _healthPoints;                     // Point de vie de l'unité
  int _price;                           // Prix de l'unité
  int _movement;                        // point de mouvement
protected:
  int _defaultMovement;                 // Point de mouvement par default
  Weapon *_primaryWeapon;               // Liste des armes
  Weapon *_secondaryWeapon;
  Weapon *_thirdWeapon;
  Weapon *_fourthWeapon;
public:
  Unit ();                              //constructeur
  ~Unit ();                             //Destructeur
  Unit(Unit&);                          // constructeur par recopie
  /** Getter **/
  std::string getName()const;
  int getHealthPoints()const;
  int getPrice()const;
  int getMovement()const;
  Weapon* getPrimaryW()const;
  Weapon* getSecondaryW()const;
  Weapon* getThirdW()const;
  Weapon* getFourthW()const;
  int getDefault()const;
  /** Setter **/
  void setDefault(int);
  void setName(std::string);
  void setHealthPoints(int);
  void setPrice(int);
  void setMovement(int);
  void setPrimaryW(Weapon*);
  void setSecondaryW(Weapon*);
  void setThirdW(Weapon*);
  void setFourthW(Weapon*);
  /** Methode **/
  virtual void attack(Unit*,int,Player&,Player&,Position,Map*){std::cout << "TU ATTAQUE AVEC UNIT " << '\n';}   // fonctionelle virtuelle d'attaque
  void move(Position,Position,Map*,int,Player&,Player&);                                                        // fonction de deplacement commune a toute les unités
  friend class Weapon;                                                                                          // class Weapon amie de la classe Unit
  Unit& operator=(Unit& u) {                                                                                    // Surcharge operataeur d'affectation
    this->_name = u._name;
    this->_healthPoints = u._healthPoints;
    this->_price = u._price;
    this->_movement = u._movement;
    this->setPosition(u.getPosition());
    return(*this);
  }
};

class Zedd : public Unit{                    // class heritant de Unit
private:                                     // class principal "enemie"
  bool _activeExpendNade;                    // booleen  et INT pour utiliser capacité
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;
  bool apoon;


public:
  Zedd ();
  ~Zedd ();
  /** GETTER **/
  int getActiveExpendNade()const;
  int getInvocation()const;
  int getPuttiesCalling()const;
  int getApocalypseHole()const;
  bool getApoon()const;
  void setApoon(bool);
  /** SETTER **/
  void setActiceExpendNade(int);
  void setInvocation(int);
  void setPuttiesCalling(int);
  void setApocalypseHole(int);
  /** Methode **/
  void ThrowExtendNade(Position,Map*,Player&);
  void EnableGrenade(Map*);
  void Invocation(Position,Map*,Player&);
  void PuttiesCalling(Position,Map*,Player&);
  void ApocalypseHole(Map*,Player&);
  void attack(Unit*,int,Player&,Player& ,Position,Map*);
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




class Putties : public Unit {                                                              // sous classe de Unit
private:

public:
  Putties ();
  ~Putties ();
  Putties(int,int,int,Weapon*,std::string= "Putties"); //hp,mvmt,price,arme
  virtual void attack(Unit*,int,Player&,Player&,Position,Map*);
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

class PowerRanger : public Unit {                               //sous classe de UNIT
private:
  std::string _color;                                           // indique la couleur du POWERANGER
  bool _capacityRobot;                                          // BOOLEN pour l'utilisation des capacité
  bool _capacityWeapon;


public:
  PowerRanger ();
  PowerRanger (std::string);
  ~PowerRanger();
  /** GETTER **/
  std::string getColor()const;
  void setCapacityRobot(bool);
  void setCapacityWeapon(bool);
  bool getCapacityRobot()const;
  bool getCapacityWeapon()const;
  int getDefault()const;
  /** SETTER **/
  void setColor(std::string);
  /** METHODE **/
  void TornadoDino(Map*,Position);
  virtual void attack(Unit*,int,Player&,Player&,Position,Map*);
  void BeTogether(Map*,Position,bool*,bool*);
  void Transformation(Map*,Player&);
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

class RobotPR : public Unit {                                           // sous classe d'unité
private:
  int _armor;                                                            // armure de l'unité
public:
  RobotPR ();
  virtual ~RobotPR ();
  /** GETTER **/
  int getArmor()const;
  /** SETTER **/
  void setArmor(int);
  /** METHODE **/
  void TransformationTurtle(Map*,Player&,Player&,Position);
  virtual void attack(Unit*,int,Player&,Player&,Position,Map*);
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

class TurtleTank : public RobotPR {                                // Sous classe de robotPR heritant lui meme de UNIT
private:

public:
  TurtleTank ();
  virtual ~TurtleTank ();
  /** METHODE **/
  virtual void attack(Unit*,int,Player&,Player&,Position,Map*);
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
