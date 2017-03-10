#include "unit.hpp"

/**** METHODE UNIT *****/
//Constructeur
Unit::Unit(){
  _name = "";
  _strengh=0;
  _attackRange =0;
  _healthPoints=0;
  _price=0;
  _energyCost=0;
}

//Destructeur
Unit::~Unit(){

}

//Getter
string Unit::getName()const{
  return(this->_name);
}

int Unit::getStrengh()const{
  return(this->_strengh);
}

int Unit::getAttackRange()const{
  return(this->_attackRange);
}

int Unit::getHealthPoints(){
  return(this->_healthPoints);
}

int Unit::getPrice()const{
  return(this->_price);
}

int Unit::getEnergyCost()const{
  return(this->_energyCost);
}

//Setter
void Unit::setName(string name){
  this->_name = name;
}

void Unit::setStrengh(int strengh){
  this->_strengh=strengh;
}

void Unit::setAttackRange(int attRange){
  this->_attackRange= attRange;
}

void Unit::setHealthPoints(int Hp){
  this->_healthPoints = Hp;
}

void Unit::setPrice(int price){
  this->_price = price;
}

void Unit::setEnergyCost(int Energy) {
  this->_energyCost = Energy;
}

/****************************************/

/*** Methode Fantassin ***/

Fantassin::Fantassin(){
  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
  _name = "Fantassin";
  _attackRange = 1;
  _healthPoints = /** REMPLIR **/ // les HP du fantassin
  _price = /** REMPLIR **/ // Le prix du fantassin
  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
}

Fantassin::~Fantassin(){

}

/*************************/

/*** Methode Archer ***/

Archer::Archer(){
  _changeArrowTime = 1;
  _typeOfArrow = 1;

  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
  _name = "Archer";
  _attackRange = 1;
  _healthPoints = /** REMPLIR **/ // les HP du fantassin
  _price = /** REMPLIR **/ // Le prix du fantassin
  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
}

Archer::~Archer(){

}

void Archer::setOnFire(){
  _typeOfArrow = 2;
}

void Archer::setOnDefault(){
  _typeOfArrow = 1;
}

int Archer::getTypeOfArrow(){
  return(this->_typeOfArrow);
}

int Archer::getChangeOfTime()const{
  return(this->_changeArrowTime);
}

void Archer::setChangeOnTime(int Arrowtime){
  this->_changeArrowTime = Arrowtime;
}

/************************************************/

/*** Methode Cavalier ***/

Cavalier::Cavalier(){
  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
  _name = "Cavalier";
  _attackRange = 1;
  _healthPoints = /** REMPLIR **/ // les HP du fantassin
  _price = /** REMPLIR **/ // Le prix du fantassin
  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
}

Cavalier::~Cavalier(){

}

/****************************************************************/

/*** Methode Catapulte ***/

Catapulte::Catapulte(){
  _reloadTime = /* REMPLIR */

  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
  _name = "Catapulte";
  _attackRange = 1;
  _healthPoints = /** REMPLIR **/ // les HP du fantassin
  _price = /** REMPLIR **/ // Le prix du fantassin
  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin

}

Catapulte::~Catapulte(){

}

/*******************************/
