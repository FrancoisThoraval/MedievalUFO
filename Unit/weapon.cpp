#include "weapon.hpp"



Weapon::Weapon(std::string name, int strengh,int range,int cost){
  this->_strengh = strengh;
  this->_attackRange = range;
  this->_cost = cost;
  this->_name = name;

}

Weapon::~Weapon(){

}

int Weapon::getStrengh()const{
  return(this->_strengh);
}

int Weapon::getAttackRange()const{
  return(this->_attackRange);
}

void Weapon::setStrengh(int strengh){
  this->_strengh=strengh;
}

void weapon::setAttackRange(int attRange){
  this->_attackRange= attRange;
}

/******************************************************/
