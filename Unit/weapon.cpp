#include "weapon.hpp"


Weapon::Weapon(){

}

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

int Weapon::getCost()const{
  return(this->_cost);
}

std::string Weapon::getName()const{
  return(this->_name);
}

void Weapon::setStrengh(int strengh){
  this->_strengh=strengh;
}

void Weapon::setAttackRange(int attRange){
  this->_attackRange= attRange;
}

void Weapon::setCost(int cost){
  this->_cost = cost;
}

void Weapon::setName(std::string name){
  this->_name = name;
}


/******************************************************/
