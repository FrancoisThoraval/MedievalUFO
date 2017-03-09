#ifndef unit_hpp
#define unit_hpp

#include "../Element/element.hpp"
#include <string>

/***** Classe des unités, class mères de tous les types d'unites ********/
class Unit;
class Fantassin;
class Archer;
class Cavalier;
class Catapulte;

class Unit : public Element {
private:
  string _name;
  int _strengh;
  int _attackRange;
  int _healthPoints;
  int _price;
  int _energyCost;
public:
  Unit ();
  virtual ~Unit ();
  string getName()const;
  /** Getter **/
  int getStrengh()const;
  int getAttackRange()const;
  int getHealthPoints()const;
  int getPrice()const;
  int getEnergyCost()const;
  /** Setter **/
  void setName(string);
  void setStrengh(int);
  void setAttackRange(int);
  void setHealthPoints(int);
  void setPrice(int);
  void setEnergyCost(int);
  /** Methode **/
  virtual attack();
  virtual move();

};

/** le fantassin est une unité de base qui n'as rien de special ... il est nul **/

class Fantassin : public Unit {
private:
  /*Vide*/
public:
  Fantassin ();
  ~Fantassin ();arguments

};

/** l'archer est une unité qui peut tirer a distance et changer de type de fleches pour faire plus mal **/

class Archer : public Unit {
private:
  int _changeArrowTime;
public:
  Archer ();
  ~Archer ();
  void setOnFire();
  void setOnDefault();
};

/** le cavalier est une unité qui peut se deplacer sur plusieur cases **/

class Cavalier : public Unit {
private:
  /* Vide */
public:
  Cavalier ();
  ~Cavalier ();

};

/** la catapulte est une unité qui peut faire de gros dommages a moyennes distances en zone **/

class Catapulte : public Unit {
private:
  int _reloadTime;
public:
  Catapulte ();
  ~Catapulte ();
};

// definir la class Unité cheater du milieu

#endif
