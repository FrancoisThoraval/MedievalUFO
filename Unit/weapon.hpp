#ifndef weapon_hpp
#define weapon_hpp

#include <string>
#include <iostream>

class Weapon {                               // classe d'une armes, elle contient sa forces, sa portée, sont nom et son prix
private:
  int _strengh;
  int _attackRange;
  int _cost;
  std::string _name;
public:
  Weapon ();
  Weapon(std::string,int,int,int);
  virtual ~Weapon ();
  /** GETTER **/
  int getStrengh()const;
  int getAttackRange()const;
  int getCost()const;
  std::string getName()const;
  /** SETTER **/
  void setStrengh(int);
  void setAttackRange(int);
  void setCost(int);
  void setName(std::string);

};


#endif
