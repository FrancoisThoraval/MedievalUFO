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
  this->_thirdWeapon = u._thirdWeapon;
  this->_fourthWeapon = u._fourthWeapon;
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

void Unit::setDefault(int d){
  this->_defaultMovement = d;
}


void Unit::setHealthPoints(int Hp){
  this->_healthPoints = Hp;
}

void Unit::setPrice(int price){
  this->_price = price;
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

void Unit::setThirdW(Weapon* wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_primaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}

void Unit::setFourthW(Weapon *wp){
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

Weapon * Unit::getThirdW()const{
  return(this->_thirdWeapon);
}

Weapon* Unit::getFourthW()const{
  return(this->_fourthWeapon);
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

void Unit::attack(Unit& u,int W,Player& p,Player &p2,Position posFinal,Map *m){

  Position posInit = this->_pos;
  if(W != 0){
      if(this->_primaryWeapon != NULL){
        std::cout<<"HP AVANT ATTAQUE :"<<u.getHealthPoints()<<std::endl;
        int distance = Distance(posInit,posFinal);
        if(W == 1){
          std::cout<<"Tu veux attaque avec : "<<this->_primaryWeapon->getName()<<std::endl;
          std::cout<<"Tu as "<<this->_primaryWeapon->getAttackRange()<<" de portée et la cible est a  "<<distance<<std::endl;
          std::cout<<"Tu as "<<p.getEnergy()<<" et ton arme consomme "<<this->_primaryWeapon->getCost()<<std::endl;
          std::cout<<"TEST1"<<std::endl;
          std::cout<<"p.getener : "<<p.getEnergy()<<std::endl;
          if(p.getEnergy()>(this->getPrimaryW())->getCost()){
            std::cout<<"TEST2"<<std::endl;
            std::cout<<"Distnce : "<<distance<<std::endl;
            std::cout<<"range : "<<(this->_primaryWeapon)->getAttackRange()<<std::endl;
            if((distance <= (this->_primaryWeapon)->getAttackRange()) || (this->_primaryWeapon->getAttackRange()==-1)){
              std::cout<<"TEST3"<<std::endl;
              if(m->getNameOfElement(posInit) != "Zedd"){
                std::cout<<"TEST4"<<std::endl;
                u.setHealthPoints(u.getHealthPoints()-this->_primaryWeapon->getStrengh());
                std::cout<<"TEST5"<<std::endl;
                p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
                std::cout<<"HP APRES ATTAQUE : "<<u.getHealthPoints()<<std::endl;
                if(u.getHealthPoints()<=0){
                  Unit dead;
                  m->setElementW1(posFinal,dead);
                }
              } else {
                std::cout<<"TEST6"<<std::endl;
                Zedd z ;
                z = m->getElementW1(posInit);
                z.ThrowExtendNade(posFinal,m,p);
              }
            } else {
              std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
            }
          } else {
            std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
          }
        }else if(W == 2) {
          std::cout<<"Tu veux attaque avec : "<<this->_secondaryWeapon->getName()<<std::endl;
          std::cout<<"Tu as "<<this->_secondaryWeapon->getAttackRange()<<" de portée et la cible est a  "<<distance<<std::endl;
          std::cout<<"Tu as "<<p.getEnergy()<<" et ton arme consomme "<<this->_secondaryWeapon->getCost()<<std::endl;
          if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
            if((distance <= (this->_secondaryWeapon)->getAttackRange()) || (this->_secondaryWeapon->getAttackRange()==-1)){
              if(m->getNameOfElement(posInit) != "Zedd"){
                u.setHealthPoints(u.getHealthPoints()-this->_secondaryWeapon->getStrengh());
                p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
                std::cout<<"HP APRES ATTAQUE : "<<u.getHealthPoints()<<std::endl;
                if(u.getHealthPoints()<=0){
                  Unit dead;
                  m->setElementW1(posFinal,dead);
                }
              } else {
                Zedd z;
                //z = m->getElementW1(posInit);
                std::cout << "/* message */" << std::endl;
                z.Invocation(posFinal,m,p);
              }

            } else {
              std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
            }
          } else {
            std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
          }
        } else if (W == 3){
          std::cout<<"TEST 3EME ARME "<<std::endl;
          // std::cout<<"Tu veux attaque avec : "<<this->_thirdWeapon->getName()<<std::endl;
          // std::cout<<"Tu as "<<this->_thirdWeapon->getAttackRange()<<" de portée et la cible est a  "<<distance<<std::endl;
          // std::cout<<"Tu as "<<p.getEnergy()<<" et ton arme consomme "<<this->_thirdWeapon->getCost()<<std::endl;
          if(p.getEnergy()>((this->_thirdWeapon)->getCost())){
            if((m->getNameOfElement(posInit) != "Putties") && (m->getNameOfElement(posInit) != "Zedd")){
              PowerRanger pr ;
              pr = m->getElementW1(posInit);
              pr.Transformation(m);

            } else {
              std::cout<<"TEST ATTACK PUTTIESCALLING"<<std::endl;
              Zedd z;
              z = m->getElementW1(posInit);
              z.PuttiesCalling(posFinal,m,p);
            }
          } else {
            std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
          }
        } else {
          std::cout<<"Tu veux attaque avec : "<<this->_fourthWeapon->getName()<<std::endl;
          std::cout<<"Tu as "<<this->_fourthWeapon->getAttackRange()<<" de portée et la cible est a  "<<distance<<std::endl;
          std::cout<<"Tu as "<<p.getEnergy()<<" et ton arme consomme "<<this->_fourthWeapon->getCost()<<std::endl;
          if(p.getEnergy()>=((this->_fourthWeapon)->getCost())){
            if((m->getNameOfElement(posInit) != "Putties") && (m->getNameOfElement(posInit) != "Zedd")){
              PowerRanger pr;
              pr = (*this);
              // pr = m->getElementW1(posInit);
              pr.CheaterWeaponOn(m);
              std::cout<<"APRES FCT CHEATEDWEAPONON"<<std::endl;
              if( pr.getCapacityWeapon()==true){
                std::cout<<"TEST GETCAPACITYWEAPON"<<std::endl;
                if((distance <= (this->_fourthWeapon)->getAttackRange()) || (this->_fourthWeapon->getAttackRange()==-1)){
                  std::cout<<"TEST RANGE"<<std::endl;
                  u.setHealthPoints(u.getHealthPoints()-this->_fourthWeapon->getStrengh());
                  p.setEnergy(p.getEnergy()-(this->_fourthWeapon)->getCost());
                  std::cout<<"HP APRES ATTAQUE : "<<u.getHealthPoints()<<std::endl;
                  if(u.getHealthPoints()<=0){
                    std::cout<<"TEST DEAD"<<std::endl;
                    Unit dead;
                    m->setElementW1(posFinal,dead);
                    p2.removeUnit(u);
                  }
                } else {
                  std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
                }
              } else {
                std::cout<<"Tu n'as pas la capacité disponible"<<std::endl;
              }
            } else {

              Zedd z ;
              z = m->getElementW1(posInit);
              z.ApocalypseHole(m,p);
            }
          } else {
            std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
          }
        }

      } else {
        std::cout<<"L'ARME VAUT NUL"<<std::endl;
      }
  } else {
      std::cout<<"Tu n'as pas d'arme selectionné"<<std::endl;
  }
}

void Unit::move(Position posInit,Position posFinal,Map* m,int numattack,Player& p,Player &p2){
  int distance = Distance(posInit,posFinal);
  if(p.isMineUnit(m->getElementW1(posInit)) == true){
    if(m->getNameOfElement(posInit)!="Zedd"){
      if((m->getNameOfElement(posFinal) != "Hill") && ( m->getNameOfElement(posFinal) != "Tree") && (m->getNameOfElement(posFinal) != "Water")&&(m->getNameOfElement(posFinal)!="")){
        if(posInit != posFinal){
          if(p.isMineUnit(m->getElementW1(posFinal)) != true){
            //(m->getElementW1(posInit)).attack(m->getElementW1(posFinal),numattack,p,posFinal,m);
            if(m->getNameOfElement(posInit)=="red"){
              Unit *red = new PowerRanger("red");
              red->setPosition(posInit);
              red->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
            } else if (m->getNameOfElement(posInit) == "green") {
                Unit *green = new PowerRanger("green");
                green->setPosition(posInit);
                green->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
            } else if (m->getNameOfElement(posInit) == "Putties"){
                Unit *putties = new Putties;
                putties->setPosition(posInit);
                putties->attack(m->getElementW1(posFinal),1,p,p2,posFinal,m);
              }  else if(m->getNameOfElement(posInit)=="Zedd"){
                  Unit *zed = new Zedd;
                  zed->setPosition(posInit);
                  zed->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
            } else {
              Unit *other = new PowerRanger("other");
              other->setPosition(posInit);
              other->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
            }
          } else  {
            std::cout<<"Tu ne peux pas attaquer ta propre unite"<<std::endl;
          }
        }

      } else {
        if(distance<=this->_movement){
          if(distance != 0){
            Unit *u = new Unit();
            int mouvementdefault = m->getElementW1(posInit).getDefault();
            m->setElementW1(posFinal,*this);
            m->setElementW1(posInit,*u);
            m->getElementW1(posFinal).setMovement(m->getElementW1(posFinal).getMovement()-(distance));
            this->setPosition(posFinal);
            m->getElementW1(posFinal).setDefault(mouvementdefault);
            //std::cout<<"Distance : "<<distance<<std::endl;
            // std::cout<<"HP : :"<<m->getElementW1(posFinal).getHealthPoints()<<std::endl;
            // std::cout<<"Movement :"<<this->getMovement()<<std::endl;
          } else {
            std::cout <<"Tu ne peux pas te deplacer sur ta case actuelle"<<std::endl;
          }
        } else {
          std::cout<<"Pas assez de point de deplacement"<<std::endl;
        }
      }
    } else {

      Unit *zed = new Zedd;
      (*zed) = m->getElementW1(posInit);
      // std::cout<<"NOM ARME : "<<zed->getSecondaryW()->getName()<<std::endl;
      // std::cout<<"NOM ARME : "<<zed->getThirdW()->getName()<<std::endl;
      zed->setPosition(posInit);
      zed->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
    }

  } else {
    std::cout<<"Cette unite ne t'appartient pas "<<std::endl;
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


Putties::Putties(int hp,int mvmt,int price,Weapon *wp,std::string nom){
  this->setName(nom);
  this->setHealthPoints(hp);
  this->setMovement(mvmt);
  this->setPrimaryW(wp);
  this->setPrice(price);
  this->_defaultMovement = this->getMovement();
}

Putties::~Putties(){

}

/*
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
*/
/*************************/




/*** CLASS POWERRANGER ***/


PowerRanger::PowerRanger(){

}

PowerRanger::PowerRanger(std::string color){
  _capacityRobot = false;
  _capacityWeapon = false;
  _thirdWeapon = new Weapon("RobotTransformation",0,0,100);
  _fourthWeapon = new Weapon("MergeWeapon",400,10,100);
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

int PowerRanger::getDefault()const{
  return(this->_defaultMovement);
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
/*
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
*/
void PowerRanger::TornadoDino(Map* m,Position pos){
  if((m->getNameOfElement(pos)=="Tree")||(m->getNameOfElement(pos)=="Hill")||(m->getNameOfElement(pos)=="Water")||(m->getNameOfElement(pos)=="Lava2")||(m->getNameOfElement(pos)=="Lava1")){
    Unit *d = new Dino;
    m->setElementW1(pos,*d);
  }
}

void PowerRanger::BeTogether(Map *m,Position pos,bool* hor, bool* ver){
  int i = 0;
  int k = 0;
  std::cout<<"IN FCT BETOGETHER"<<std::endl;
  std::cout<<"premiere pos p.X "<<pos.getX()<<" p.Y : "<<pos.getY()<<std::endl;
  Position currentPos;
  currentPos.setY(pos.getY());
  std::cout<<"TEST BOUCLE 1"<<std::endl;
  for(int j =0;j<m->getSizeX();j++){
    currentPos.setX(j);
    std::cout<<"posX : "<<currentPos.getX()<<std::endl;
    std::cout<<"posY : "<<currentPos.getY()<<std::endl;
    if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
      i++;
    }
  }
  currentPos.setX(pos.getX());
  std::cout<<"TEST BOUCLE 2"<<std::endl;
  for(int j =0;j<m->getSizeY();j++){
    currentPos.setY(j);
    std::cout<<"posX : "<<currentPos.getX()<<std::endl;
    std::cout<<"posY : "<<currentPos.getY()<<std::endl;
    if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
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
  std::cout<<"TEST FIN BOUCLE BETOGETHER"<<std::endl;
}

void PowerRanger::Transformation(Map *m){
  Position pos = this->_pos;
  Position currentPos;
  Unit *u = new Unit;

  Unit *r =  new RobotPR;
  bool hor =false;
  bool ver = false;
  BeTogether(m,pos,&hor,&ver);
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

void PowerRanger::CheaterWeaponOn(Map *m){
  bool hor = false;
  bool ver = false;
  Position pos = this->_pos;
  BeTogether(m,pos,&hor,&ver);
  if((hor == true)||(ver == true)){
    this->_capacityWeapon = true;
  } else {
    this->_capacityWeapon = false;
  }
  std::cout<<"TEST FIN FCT CHEATERWEAPONON"<<std::endl;
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
//
//
// AYAYAY_Assistant::AYAYAY_Assistant(){
//
// }
//
// AYAYAY_Assistant::~AYAYAY_Assistant(){
//
// }
//
// void AYAYAY_Assistant::setAdvice(std::string advice){
//   this->_advice = advice;
// }
//
// std::string AYAYAY_Assistant::getAdvice()const{
//   return(this->_advice);
// }

/******************************************************/

/**** CLASS ZEDD ***/


Zedd::Zedd(){
  _activeExpendNade = false;
  _primaryWeapon = new Weapon("Grenade",0,-1,100);
  _secondaryWeapon = new Weapon("Invocation",0,-1,50);
  _thirdWeapon = new Weapon("PuttiesCalling",0,-1,50);
  _fourthWeapon = new Weapon("ApocalypseHole",1200,0,100);
  setName("Zedd");
  setHealthPoints(500);
  setPuttiesCalling(0);
  setInvocation(0);
  setApocalypseHole(0);
  apoon = false;
  //std::cout<<"ARME : "<<_thirdWeapon->getName()<<std::endl;
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
  this->_invocation = invoc;
}

void Zedd::setPuttiesCalling(int putties){
  this->_puttiesCalling = putties;
}

void Zedd::setApocalypseHole(int hole){
  this->_apocalypseHole = hole;
}

void Zedd::EnableGrenade(Map m){
  Position currentPos;
  for(int i = 0;i<m.getSizeX();i++){
    for(int j=0;j<m.getSizeY();j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m.getNameOfElement(currentPos)=="Putties"){
        if((m.getElementW1(currentPos)).getHealthPoints()<= 40){
          this->_activeExpendNade = true;
        }
      }
    }
  }
}


void Zedd::ThrowExtendNade(Position pos,Map *m,Player& p){
    this->EnableGrenade(*m);
    if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
      if(this->getActiveExpendNade()==true){
        if((m->getNameOfElement(pos))=="Putties") {
          (m->getElementW1(pos)).setHealthPoints(1500);
          Weapon *wp = new Weapon("Big attack",200,1,60);
          (m->getElementW1(pos)).setPrimaryW(wp);
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        } else {
          std::cout <<"Mauvais personnage a boost"<<std::endl;
        }
      } else {
        std::cout<<"Tu ne peux pas encore utiliser cette capacité"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
}


/**** PAS SUR DE CELLE CI *****/
void Zedd::Invocation(Position pos, Map *m,Player& p){
    if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
      if(this->getInvocation() == 0){
        if(m->getNameOfElement(pos)!= ""){
          int hp;
          int mvmt;
          Weapon *wp;
          if(m->getElementW2(pos).getName()=="Water"){
            hp = 250;
            mvmt = 1;
            wp = new Weapon("Canon a eau",150,1,50);
          } else if (m->getElementW2(pos).getName()=="Hill"){
            hp = 300;
            mvmt = 3;
            wp = new Weapon("Lancer de terre",120,3,50);
          } else if(m->getElementW2(pos).getName()=="Tree"){
            hp = 150;
            mvmt = 4;
            wp = new Weapon("Lancer de tronc",210,4,60);
          }
          Unit *u = new Putties(hp,mvmt,60,wp);
          m->setElementW1(pos,*u);
          p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
          this->_invocation= 5;                                  // WARNING WARNING WARNING
        } else {
          std::cout<<"There's already something on this tile !"<<std::endl;
        }
      } else {
        std::cout<<"Be patient my friend !"<<std::endl;
      }
    } else {
      std::cout<<"You don't have enough energy !"<<std::endl;
    }
}


void Zedd::PuttiesCalling ( Position pos, Map* m,Player& p){
  std::cout << "IN FCT PUTTIESCALLING" << std::endl;
    if(p.getEnergy()>((this->_thirdWeapon)->getCost())){
      if(this->_puttiesCalling==0){
        Position p1 = pos;
        p1.setY(pos.getY()+1);
        Position p2 = pos;
        p2.setY(pos.getY()-1);
        Position p3 = pos;
        p3.setX(pos.getX()+1);
        Position p4 = pos;
        p4.setX(pos.getX()-1);
        if((m->isOnMap(pos))&&(m->isOnMap(p1))&&(m->isOnMap(p2))&&(m->isOnMap(p3))&&(m->isOnMap(p4))){
          if((m->getElementW1(pos).getName()=="")&&(m->getElementW1(p1).getName()=="")&&(m->getElementW1(p2).getName()=="")&& (m->getElementW1(p3).getName()=="")&&(m->getElementW1(p4).getName()=="")){
            Weapon *wp = new Weapon("Default",5,1,20);
            Unit *n1 = new Putties;
            n1->setMovement(3);
            m->setElementW1(pos,*n1);
            m->getElementW1(pos).setPosition(pos);
            p.pushUnit(m->getElementW1(pos));
            m->setElementW1(p1,*n1);
            m->getElementW1(p1).setPosition(p1);
            p.pushUnit(m->getElementW1(p1));
            m->setElementW1(p2,*n1);
            m->getElementW1(p2).setPosition(p2);
            p.pushUnit(m->getElementW1(p2));
            m->setElementW1(p3,*n1);
            m->getElementW1(p3).setPosition(p3);
            p.pushUnit(m->getElementW1(p3));
            m->setElementW1(p4,*n1);
            m->getElementW1(p4).setPosition(p4);
            p.pushUnit(m->getElementW1(p4));
            p.setEnergy(p.getEnergy()-(this->_thirdWeapon)->getCost());
            this->_puttiesCalling = 4;
            std::cout << "TEST A LA FIN DE PUTTIESCALLING" << std::endl;
          } else {
            std::cout<<"There's already something on this tile !"<<std::endl;
          }
        } else {
          std::cout<<"Out of bounds !"<<std::endl;
        }
      } else {
        std::cout<<"Not available !"<<std::endl;
      }
    } else {
      std::cout<<"You don't have enough energy"<<std::endl;
    }
}


void Zedd::ApocalypseHole(Map *m,Player& p){

  static int count = 0;

  if(this->apoon == false ){
      if(p.getEnergy() >=((this->_fourthWeapon)->getCost())){
        std::cout << "/* message */" << std::endl;
        if(this->apoon == false){
          std::cout << "/* message2 */" << std::endl;
          m->getElementW2(this->_pos).setName("Lava2");
          std::cout << "/* message3 */" << std::endl;
          p.setEnergy(p.getEnergy()-(this->_fourthWeapon)->getCost());
          std::cout << "/* message4 */" << std::endl;
          //count++;
          this->apoon = true;
          std::cout << "map : " <<m->getElementW2(this->_pos).getName()<< std::endl;
        }
      }else {
        std::cout<<"You don't have enough energy"<<std::endl;
      }
    } else {
      std::cout << "/* message5 */" << std::endl;
      Position p1 ;
      Position p2 ;
      Position p3 ;
      Position p4 ;
      Position currentPos;
      Scenery *lava = new Lava;
      for(int i =0;i<m->getSizeX();i++){
        for(int j = 0;j< m->getSizeY();j++){
          currentPos.setX(i);
          currentPos.setY(j);

          p1 = currentPos;
          p1.setX(currentPos.getX());
          p1.setY(currentPos.getY()+1);

          p2 = currentPos;
          p2.setX(currentPos.getX());
          p2.setY(currentPos.getY()-1);

          p3 = currentPos;
          p3.setX(currentPos.getX()+1);
          p3.setY(currentPos.getY());

          p4 = currentPos;
          p4.setX(currentPos.getX()-1);
          p4.setY(currentPos.getY());
          if((m->getElementW2(currentPos).getName()=="Lava2")){

                if((m->isOnMap(p1))) {
                  m->setElementW2(p1,*lava);
                  m->getElementW2(p1).setName("Lava1");
                }
                if(m->isOnMap(p2)) {
                  m->setElementW2(p2,*lava);
                  m->getElementW2(p2).setName("Lava1");
                }
                if(m->isOnMap(p3)) {
                  m->setElementW2(p3,*lava);
                  m->getElementW2(p3).setName("Lava1");
                }
                if(m->isOnMap(p4)) {
                  m->setElementW2(p4,*lava);
                  m->getElementW2(p4).setName("Lava1");
                }

          }
        }
      }
      for(int i =0;i<m->getSizeX();i++){
        for(int j = 0;j< m->getSizeY();j++){
          currentPos.setX(i);
          currentPos.setY(j);
          if(m->getElementW2(currentPos).getName()=="Lava1"){
                m->getElementW2(currentPos).setName("Lava2");
          }
        }
      }
    }
  }


/*********************************************************/





/****************************************************/


// Robot PR

RobotPR::RobotPR(){
  this->setArmor(1000);
  this->setHealthPoints(1000);
  this->setName("RobotPR");
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
/*
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
*/

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
/*
void TurtleTank::attack(Unit& u,int W,Player& p,Position posFinal){
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
}*/
