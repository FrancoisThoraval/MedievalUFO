#ifndef weapon_hpp
#define weapon_hpp

#include <string>
#include <iostream>

class Weapon {
private:
  int _strengh;
  int _attackRange;
  int _cost;
  std::string _name;
public:
  Weapon ();
  virtual ~Weapon ();
  int getStrengh()const;
  int getAttackRange()const;

  void setStrengh(int);
  void setAttackRange(int);
};


 #endif
