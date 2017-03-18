#include "unit.hpp"

/**** METHODE UNIT *****/
//Constructeur
Unit::Unit(){
  _name = "";
  _healthPoints=0;
  _price=0;
  _movement = 0;
}

//Destructeur
Unit::~Unit(){

}

//Getter
std::string Unit::getName()const{
  return(this->_name);
}



int Unit::getHealthPoints()const{
  return(this->_healthPoints);
}

int Unit::getPrice()const{
  return(this->_price);
}



//Setter
void Unit::setName(std::string name){
  this->_name = name;
}



void Unit::setHealthPoints(int Hp){
  this->_healthPoints = Hp;
}

void Unit::setPrice(int price){
  this->_price = price;
}



void Unit::move(){

}

void Unit::attack(){

}

int Unit::getMovement()const {
  return(this->_movement);
}

void Unit::setMovement(int mvmt){
  this->_movement = mvmt;
}

Weapon* Unit::getPrimaryW()const{
  return(this->_primaryWeapon);
}

void Unit::setPrimaryW(Weapon *wp){
  if(wp = NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_primaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}


Weapon* Unit::getSecondary()const{
  return(this->_secondaryWeapon);
}

void Unit::setSecondaryW(Weapon *wp){
  if(wp = NULL){
    Weapon *Nwp = new Weapon("Default",0,0,0);
    this->_primaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}
/****************************************/

/*** Methode Fantassin ***/

Putties::Putties(){

  this->setName("Putties");
  this->setHealthPoints(50); // les HP du Putties
  this->setPrice(5);  // Le prix du Putties
  this->setMovement(2);
  _primaryWeapon = new Weapon("fist",5,1,20);
}


Putties::Putties(int hp,int mvmt,Weapon *wp){
  this->setName("Putties");
  this->setHealthPoints(hp);
  this->setMovement(mvmt);
  this->setPrimaryW(wp);
}

Putties::~Putties(){

}


void Putties::attack(Unit& a,int W){
  if(W == 1){
      a.setHealthPoints(a.getHealthPoints()-this->getPrimaryW()->getStrengh());
  }else {
      a.setHealthPoints(a.getHealthPoints()-this->getSecondaryW()->getStrengh());
  }

}

/*************************/



/*** CLASS POWERRANGER ***/


PowerRanger::PowerRanger(std::string color){
  _capacityRobot = false;
  _capacityWeapon = false;
  this->setMovement(4);
  if(color == "red"){
    _primaryWeapon = new Weapon("Fist",60,1,30);
    _secondaryWeapon = new Weapon("Gun",20,10,30);
    this->setName(color);
    this->setHealthPoints(300); // les HP du Putties
  } else if (color == "green"){
            _primaryWeapon = new Weapon("Fist",20,1,30);
            _secondaryWeapon = new Weapon("Flute",0,0,50);
            this->setName(color);
            this->setHealthPoints(50); // les HP du Putties
          } else {
                  _primaryWeapon = new Weapon("Fist",40,1,30);
                  _secondaryWeapon = new Weapon("Gun",15,10,30);
                  this->setName(color);
                  this->setHealthPoints(200); // les HP du Putties
          }

}

PowerRanger::~PowerRanger(){

}

void PowerRanger::setColor(std::string color){
  this->_color = color;
}

std::string PowerRanger::getColor()const{
  return(this->_color);
}

void PowerRanger::setCapacityRobot(bool cap){
  this->_capacityRobot = cap;
}

void PowerRanger::setCapacityWeapon(bool cap){
  this->_capacityWeapon = cap;
}

bool PowerRanger::getCapacityRobot()const{
  return(this->_capacityRobot);
}

bool PowerRanger::getCapacityWeapon()const{
  return(this->_capacityWeapon);
}

void PowerRanger::attack(Unit& u,int W){
  if(W == 1){
      u.setHealthPoints(u.getHealthPoints()-this->_primaryWeapon->getStrengh());
  }else {
      u.setHealthPoints(u.getHealthPoints()-this->_secondaryWeapon->getStrengh());
  }

}
/******************************************************/


/*** CLASS AYAYAY ASSISTANT ***/


AYAYAY_Assistant::AYAYAY_Assistant(){

}

AYAYAY_Assistant::~AYAYAY_Assistant(){

}

void AYAYAY_Assistant::setAdvice(std::string advice){
  this->_advice = advice;
}

std::string AYAYAY_Assistant::getAdvice()const{
  return(this->_advice);
}

/******************************************************/


/*** CLASS ZERG ***/

Zedd::Zedd(){
  _activeExpendNade = false;
  _invocation = 0;
  _puttiesCalling = 0;
  _apocalypseHole = 10;
  this->setName("Zedd");
  _primaryWeapon = new Weapon("Grenade",0,-1,100);
  _secondaryWeapon = new Weapon("Invocation",0,-1,50);
  _thirdWeapon = new Weapon("PuttiesCalling",0,-1,50);
  _fourthWeapon = new Weapon("ApocalypseHole",1200,0,100);
}

Zedd::~Zedd(){

}

int Zedd::getActiveExpendNade()const{
  return(this->_activeExpendNade);
}

int Zedd::getInvocation()const{
  return(this->_invocation);
}

int Zedd::getPuttiesCalling()const{
  return(this->_puttiesCalling);
}

int Zedd::getApocalypseHole()const{
  return(this->_apocalypseHole);
}

void Zedd::setActiceExpendNade(int nade){
  this->_activeExpendNade = nade;
}

void Zedd::setInvocation(int invoc){
  this->_invocation;
}

void Zedd::setPuttiesCalling(int putties){
  this->_puttiesCalling = putties;
}

void Zedd::setApocalypseHole(int hole){
  this->_apocalypseHole = hole;
}

void Zedd::ThrowExtendNade(Position pos){
  if(this->getActiveExpendNade()==true){
    if((this->getElementOnPos(pos)).getName()=="Putties") {
      (this->getElementOnPos(pos)).setHealthPoints(1500);
      (this->getElementOnPos(pos)).setStrengh(200);
    } else {
      std::cout <<"Mauvais personnage a boost"<<std::endl;
    }
  } else {
      std::cout<<"Tu ne peux pas encore utiliser cette capacité"<<std::endl;
  }
}
/**** PAS SUR DE CELLE CI *****/
void Zedd::Invocation(Position pos){
  if(this->getInvocation() == 0){
    if(this->getElementOnPos(pos)!= NULL){
        int strengh;
        int hp;
        int range;
        int mvmt;
        Weapon *wp;
        if((this->getElementOnPos(pos)).getName()=="Water"){
          strengh = 60;
          hp = 250;
          range = 1;
          mvmt = 1;
          wp = new Weapon("Canon a eau",150,1,50);
        } else if ((this->getElementOnPos(pos)).getName()=="Hill"){
                  strengh = 70;
                  hp = 300;
                  range = 3;
                  mvmt = 3;
                  wp = new Weapon("Lancer de terre",120,3,50);
                } else if((this->getElementOnPos(pos)).getName()=="Tree"){
                          strengh = 50;
                          hp = 150;
                          range = 1;
                          mvmt = 4;
                          wp = new Weapon("Lancer de tronc",210,4,60);
                        }
          Unit *u = new Putties(hp,mvmt,wp);
          this->setElementPosition(pos,u);                                        // WARNING WARNING WARNING
        } else {
          std::cout<<"Il y a deja quelque chose sur cette case"<<std::endl;
        }
  } else {
    std::cout<<"Tu ne peux pas encore utiliser cette capacite"<<std::endl;
  }
}

/*
void PuttiesCalling(Position pos){
  if()
    if((this->getElementOnPos(pos)!= NULL)&&)
}
*/


/****************************************************/


/*** Robot PR ***/

RobotPR::RobotPR(){
  this->setArmor(1000);
  this->setHealthPoints(1000);
  _primaryWeapon = new Weapon("Fist",300,1,60);
  _secondaryWeapon = new Weapon("Sword",600,3,100);
  this->setMovement(5);
}

RobotPR::~RobotPR(){

}

int RobotPR::getArmor()const{
  return( this->_armor);
}

void RobotPR::setArmor(int armor){
  this->_armor = armor;
}

void RobotPR::attack(Unit& u,int W){
  if(W ==  1){
    u.setHealthPoints(u.getHealthPoints()-this->getPrimaryW()->getStrengh());
  } else if (W == 2){
        u.setHealthPoints(u.getHealthPoints()-this->getSecondary()->getStrengh());
  }
}


/*************************************************/


/*** TurtleTank ***/

TurtleTank::TurtleTank(){
    setHealthPoints(10000);
    setArmor(10000);
    setName("TurtleTank");
    _primaryWeapon = new Weapon("Fatality",10000,30,100);
    setMovement(5);
}

TurtleTank::~TurtleTank(){

}

void TurtleTank::attack(Unit& u){
  u.setHealthPoints(u.getHealthPoints()-this->getPrimaryW()->getStrengh());
}
/*** Methode Archer ***/
/*
Archer::Archer(){
//_changeArrowTime = 1;
//  _typeOfArrow = 1;

//  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
//  _name = "Archer";
//  _attackRange = 1;
//  _healthPoints = /** REMPLIR **/ // les HP du fantassin
//  _price = /** REMPLIR **/ // Le prix du fantassin
//  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
//}
/*
Archer::~Archer(){

}

void Archer::setOnFire(){
_typeOfArrow = 2;
}

void Archer::setOnDefault(){
_typeOfArrow = 1;
}

int Archer::getTypeOfArrow()const{
return(this->_typeOfArrow);
}

int Archer::getChangeOfTime()const{
return(this->_changeArrowTime);
}

void Archer::setChangeOnTime(int Arrowtime){
this->_changeArrowTime = Arrowtime;
}

void Archer::attack(Unit& a){
a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
}
/************************************************/

/*** Methode Cavalier ***/

//Cavalier::Cavalier(){
//  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
//  _name = "Cavalier";
//  _attackRange = 1;
//  _healthPoints = /** REMPLIR **/ // les HP du fantassin
//  _price = /** REMPLIR **/ // Le prix du fantassin
//  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
//}

//Cavalier::~Cavalier(){

//}
/*
void Cavalier::attack(Unit& a){
a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
}

/****************************************************************/

/*** Methode Catapulte ***/
/*
Catapulte::Catapulte(){
//_reloadTime = /* REMPLIR */

//  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
//  _name = "Catapulte";
//  _attackRange = 1;
//  _healthPoints = /** REMPLIR **/ // les HP du fantassin
//  _price = /** REMPLIR **/ // Le prix du fantassin
//  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin

//}
/*
Catapulte::~Catapulte(){

}

void Catapulte::attack(Unit& a){
a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
}
/*******************************/
