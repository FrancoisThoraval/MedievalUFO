#include "unit.hpp"

int Distance(Position posInit,Position posFinal){
  int max;
  int min;
  int max2;
  int min2;
  if(posInit.getX()>posFinal.getX()){
    max = posInit.getX();
    min = posFinal.getX();
  } else {
    max = posFinal.getX();
    min = posInit.getX();
  }
  if(posInit.getY()>posFinal.getY()){
    max2 = posInit.getY();
    min2 = posFinal.getY();
  } else {
    max2 = posFinal.getY();
    min2 = posInit.getY();

  }
  return((max-min)+(max2-min2));
}

/**** METHODE UNIT *****/
//Constructeur
Unit::Unit(){
  _name = "";
  _healthPoints=0;
  _price=0;
  _movement = 0;
  _defaultMovement = _movement;
}

//Destructeur
Unit::~Unit(){

}

Unit::Unit(Unit& u){

  this->_name = u._name;
  this->_healthPoints = u._healthPoints;
  this->_price = u._price;
  this->_movement = u._movement;
  this->_primaryWeapon = u._primaryWeapon;
  this->_secondaryWeapon = u._secondaryWeapon;
  this->_defaultMovement = u._defaultMovement;

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
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_primaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}


Weapon* Unit::getSecondaryW()const{
  return(this->_secondaryWeapon);
}

void Unit::setSecondaryW(Weapon *wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",0,0,0);
    this->_primaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}

int Unit::getDefault()const{
  return(this->_defaultMovement);
}


void Unit::move(Position posInit,Position posFinal,Map* m){
  int distance = Distance(posInit,posFinal);
   if(distance<=this->_movement){
     if(distance != 0){
       Unit *u = new Unit();
       m->setElementW1(posFinal,*this);
       m->setElementW1(posInit,*u);
       this->setMovement(this->getMovement()-(distance));
     } else {
       std::cout <<"Tu ne peux pas te deplacer sur ta case actuel"<<std::endl;
     }
   } else {
     std::cout<<"Pas assez de point de deplacement"<<std::endl;
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
  _defaultMovement = this->getMovement();
}


Putties::Putties(int hp,int mvmt,int price,Weapon *wp){
  this->setName("Putties");
  this->setHealthPoints(hp);
  this->setMovement(mvmt);
  this->setPrimaryW(wp);
  this->setPrice(price);
  this->_defaultMovement = this->getMovement();
}

Putties::~Putties(){

}


void Putties::attack(Unit& a,int W,Player& p,Position posFinal){
Position posInit = this->_pos;
int distance = Distance(posInit,posFinal);
  if(W == 1){
    if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
      if(distance <= (this->_primaryWeapon)->getAttackRange()) {
        a.setHealthPoints(a.getHealthPoints()-this->getPrimaryW()->getStrengh());
        p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
      } else {
        std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
  }else {
    if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
      if(distance <= (this->_secondaryWeapon)->getAttackRange()){
        a.setHealthPoints(a.getHealthPoints()-this->getSecondaryW()->getStrengh());
        p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
      } else {
       std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
  }

}

/*************************/

/*** CLASS ZERG ***/



/*** CLASS POWERRANGER ***/


PowerRanger::PowerRanger(){

}

PowerRanger::PowerRanger(std::string color){
  _capacityRobot = false;
  _capacityWeapon = false;
  _robot = new Weapon("RobotTransformation",0,0,100);
  _cheatedWeapon = new Weapon("MergeWeapon",400,10,100);
  this->setMovement(3);
  _defaultMovement = this->getMovement();

  this->setMovement(4);
  if(color == "red"){
    _primaryWeapon = new Weapon("Fist",60,1,30);
    _secondaryWeapon = new Weapon("Gun",20,10,30);
    this->setName(color);
    this->setHealthPoints(300); // les HP du Putties
  } else if (color == "green"){
            _primaryWeapon = new Weapon("Fist",20,1,30);
            _secondaryWeapon = new Weapon("Flute",0,-1,50);
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

void PowerRanger::attack(Unit& u,int W,Player& p,Map *m,Position posFinal){
  Position posInit = this->_pos;
  int distance = Distance(posInit,posFinal);
  if(W == 1){
      if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
        if(distance <= (this->_primaryWeapon)->getAttackRange()){
          u.setHealthPoints(u.getHealthPoints()-this->_primaryWeapon->getStrengh());
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        } else {
          std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
  }else if(W == 2) {
          if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
            if(distance <= (this->_primaryWeapon)->getAttackRange()){
              u.setHealthPoints(u.getHealthPoints()-this->_secondaryWeapon->getStrengh());
              p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
            } else {
              std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
            }
          } else {
            std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
          }
    } else if (W == 3){
              if(p.getEnergy()>((this->_robot)->getCost())){
                this->Transformation(m);
              } else {
                std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
              }
            } else {
                if(p.getEnergy()>((this->_cheatedWeapon)->getCost())){
                  this->CheaterWeaponOn(*m);
                  if(this->getCapacityWeapon()==true){
                    if(distance <= (this->_cheatedWeapon)->getAttackRange()){
                      u.setHealthPoints(u.getHealthPoints()-this->_cheatedWeapon->getStrengh());
                      p.setEnergy(p.getEnergy()-(this->_cheatedWeapon)->getCost());
                    } else {
                      std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
                    }
                  } else {
                    std::cout<<"Tu n'as pas la capacité disponible"<<std::endl;
                  }
                } else {
                  std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
                }
            }

}

void PowerRanger::TornadoDino(Map* m,Position pos){
  if((m->getNameOfElement(pos)=="Tree")||(m->getNameOfElement(pos)=="Hill")||(m->getNameOfElement(pos)=="Water")||(m->getNameOfElement(pos)=="Lava2")||(m->getNameOfElement(pos)=="Lava1")){
    Unit *d = new Dino;
    m->setElementW1(pos,*d);
  }
}

void PowerRanger::BeTogether(Map m,Position pos,bool* hor, bool* ver){
  int i = 0;
  int k = 0;
  Position currentPos;
  currentPos.setY(pos.getY());
  for(int j =0;j<m.getSizeX();j++){
    currentPos.setX(j);
    if((m.getNameOfElement(currentPos)!="Putties")&&(m.getNameOfElement(currentPos)!="Zedd")&&(m.getNameOfElement(currentPos)!="green")){
      i++;
    }
  }
  currentPos.setX(pos.getX());
  for(int j =0;j<m.getSizeY();j++){
    currentPos.setY(j);
    if((m.getNameOfElement(currentPos)!="Putties")&&(m.getNameOfElement(currentPos)!="Zedd")&&(m.getNameOfElement(currentPos)!="green")){
      k++;
    }
  }
  if(i>=5){
    (*hor)=true;
  } else if(k>=5){
    (*ver)=true;
  } else {
    (*hor)=false;
    (*ver)=false;
  }

}

void PowerRanger::Transformation(Map *m){
  Position pos = this->_pos;
  Position currentPos;
  Unit *u = new Unit;

  Unit *r =  new RobotPR;
  bool hor;
  bool ver;
  BeTogether(*m,pos,&hor,&ver);
  if((hor == true)||(ver == true)){
      this->_capacityRobot = true;
      if(hor == true){
        currentPos.setY(pos.getY());
        for(int j=0;j<m->getSizeX();j++){
          currentPos.setX(j);
          if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
            m->setInTab(m->getElementW1(currentPos));
            m->setElementW1(currentPos,*u);
          }
        }
      } else if ( ver == true){
        currentPos.setX(pos.getX());
        for(int j=0;j<m->getSizeY();j++){
          currentPos.setY(j);
          if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
            m->setInTab(m->getElementW1(currentPos));
            m->setElementW1(currentPos,*u);
          }
        }
      }
      m->setElementW1(pos,*r);
  }
}

void PowerRanger::CheaterWeaponOn(Map m){
  bool hor;
  bool ver;
  Position pos = this->_pos;
  BeTogether(m,pos,&hor,&ver);
  if((hor == true)||(ver == true)){
    this->_capacityWeapon = true;
  } else {
    this->_capacityWeapon = false;
  }
}


/******************************************************/


/*** class Dino ***/

Dino::Dino(){
    this->setName("TornadoDino");
    this->setHealthPoints(150);
    this->setMovement(3);
    _primaryWeapon = new Weapon("Tornado",0,0,50);
    this->_defaultMovement = this->getMovement();
}

Dino::~Dino(){

}



/********************************************************/


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




/*
void PuttiesCalling(Position pos){
  if()
    if((this->getElementOnPos(pos)!= NULL)&&)
}
*/


/****************************************************/


// Robot PR

RobotPR::RobotPR(){
  this->setArmor(1000);
  this->setHealthPoints(1000);
  _primaryWeapon = new Weapon("Fist",300,1,60);
  _secondaryWeapon = new Weapon("Sword",600,3,100);
  this->setMovement(5);
  this->_defaultMovement = this->getMovement();
}

RobotPR::~RobotPR(){

}

int RobotPR::getArmor()const{
  return( this->_armor);
}

void RobotPR::setArmor(int armor){
  this->_armor = armor;
}

void RobotPR::attack(Unit& u,int W,Player& p,Position posFinal){
  Position posInit = this->_pos;
  int distance = Distance(posInit,posFinal);
  if(W ==  1){
      if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
        if(distance <= (this->_primaryWeapon)->getAttackRange()){
          u.setHealthPoints(u.getHealthPoints()-this->getPrimaryW()->getStrengh());
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        } else {
            std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
  } else if (W == 2){
              if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
                if(distance <= (this->_secondaryWeapon)->getAttackRange()){
                  u.setHealthPoints(u.getHealthPoints()-this->getSecondaryW()->getStrengh());
                  p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
                } else {
                  std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
                }
              } else {
                std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
              }
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
    this->_defaultMovement = this->getMovement();
}

TurtleTank::~TurtleTank(){

}

void TurtleTank::attack(Unit& u,Player& p,Position posFinal){
  Position posInit = this->_pos;
  int distance = Distance (posInit,posFinal);
    if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
      if(distance <= (this->_primaryWeapon)->getAttackRange()){
        u.setHealthPoints(u.getHealthPoints()-this->getPrimaryW()->getStrengh());
        p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
      } else {
        std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
}
/*** Methode Archer ***/

// Archer::Archer(){
//_changeArrowTime = 1;
//  _typeOfArrow = 1;

//  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
//  _name = "Archer";
//  _attackRange = 1;
//  _healthPoints = /** REMPLIR **/ // les HP du fantassin
//  _price = /** REMPLIR **/ // Le prix du fantassin
//  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin
//}

// Archer::~Archer(){
//
// }
//
// void Archer::setOnFire(){
// _typeOfArrow = 2;
// }
//
// void Archer::setOnDefault(){
// _typeOfArrow = 1;
// }
//
// int Archer::getTypeOfArrow()const{
// return(this->_typeOfArrow);
// }
//
// int Archer::getChangeOfTime()const{
// return(this->_changeArrowTime);
// }
//
// void Archer::setChangeOnTime(int Arrowtime){
// this->_changeArrowTime = Arrowtime;
// }
//
// void Archer::attack(Unit& a){
// a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
// }
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
//
// void Cavalier::attack(Unit& a){
// a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
// }

/****************************************************************/

/*** Methode Catapulte ***/

// Catapulte::Catapulte(){
//_reloadTime = /* REMPLIR */

//  _strengh = /** REMPLIR **/     // le nombre d'attaque du fantassin
//  _name = "Catapulte";
//  _attackRange = 1;
//  _healthPoints = /** REMPLIR **/ // les HP du fantassin
//  _price = /** REMPLIR **/ // Le prix du fantassin
//  _energyCost = /** REMPLIR **/ // le cout en energie du fantassin

//}

// Catapulte::~Catapulte(){
//
// }
//
// void Catapulte::attack(Unit& a){
// a.setHealthPoints(a.getHealthPoints()-(this->getStrengh()));
// }
/*******************************/
