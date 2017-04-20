#include "unit.hpp"

/************************************************************************
*************************************************************************
COMMENTAIRE :






Les fonctions d'attaques sont par unité mais elle reste a peu pres les
mêmes leurs implementations, je decris la fonction d'attaques pour les
PUTTIES seulement



************************************************************************
***********************************************************************/


int Distance(Position posInit,Position posFinal){                      // fonction permettant de calculer la distance entre 2 point dans la map pour les attaques et les deplacementq
  int max;                                                             // Je recupere la position initial (posInit) et la position final (posFinal)
  int min;                                                             // je prends le max et le min du X et du Y entre les deux
  int max2;                                                            // je fais une soustraction entre le max et le min puis max2 et min2 puis une addition entre les deux resultats
  int min2;                                                            // et je recupere avec cette operation la distance
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
Unit::Unit(){                                                           // CONSTRUCTEUR UNIT
  _name = "";
  _healthPoints=0;
  _price=0;
  _movement = 0;
  _defaultMovement = _movement;
}

//Destructeur
Unit::~Unit(){                                                          // DESTRUCTEUR UNIT
  delete _primaryWeapon;
  delete _secondaryWeapon;
  delete _thirdWeapon;
  delete _fourthWeapon;
}

Unit::Unit(Unit& u){                                                    // CONSTRUCTEUR PAR RECOPIE UNIT

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

//***************************************************
//************ GETTER *******************************
//***************************************************
std::string Unit::getName()const{
  // std::cout << "IN FCT GETNAME UNIT" << '\n';
  return(this->_name);
}

int Unit::getHealthPoints()const{
  return(this->_healthPoints);
}

int Unit::getPrice()const{
  return(this->_price);
}

int Unit::getMovement()const {
  return(this->_movement);
}

Weapon* Unit::getPrimaryW()const{
  return(this->_primaryWeapon);
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

int Unit::getDefault()const{
  return(this->_defaultMovement);
}

//**************************************************
//*********** SETTER *******************************
//**************************************************

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



void Unit::setMovement(int mvmt){
  this->_movement = mvmt;
}


void Unit::setPrimaryW(Weapon *wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_primaryWeapon = Nwp;
  } else {
    this->_primaryWeapon = wp;
  }
}

void Unit::setThirdW(Weapon* wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_thirdWeapon = Nwp;
  } else {
    *(this->_thirdWeapon )= *wp;
  }
}

void Unit::setFourthW(Weapon *wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",5,1,20);
    this->_fourthWeapon = Nwp;
  } else {
    this->_fourthWeapon = wp;
  }
}


void Unit::setSecondaryW(Weapon *wp){
  if(wp == NULL){
    Weapon *Nwp = new Weapon("Default",0,0,0);
    this->_secondaryWeapon = Nwp;
  } else {
    this->_secondaryWeapon = wp;
  }
}

//****************************************************
//*********** METHODE ********************************
//****************************************************


void Unit::move(Position posInit,Position posFinal,Map* m,int numattack,Player& p,Player &p2){
  int distance = Distance(posInit,posFinal);
  //std::cout << "/* message1 */" << '\n';
  if(m->getElementW1(posInit) != NULL) {
    //std::cout << "/* message2 */" << '\n';
    if(p.isMineUnit(m->getNameOfElement(posInit))==true){
      //std::cout << "/* message3 */" << '\n';
      if(m->getNameOfElement(posInit ) == "Zedd"){
        m->getElementW1(posInit)->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
      } else {
        if((((m->getNameOfElement(posInit) == "red")||(m->getNameOfElement(posInit) == "blue")||(m->getNameOfElement(posInit) == "yellow")||(m->getNameOfElement(posInit) == "green")||(m->getNameOfElement(posInit) == "pink")) && (numattack == 3))){
          m->getElementW1(posInit)->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
        } else {
          if((m->getNameOfElement(posInit) == "green") && (numattack == 2)) {
            m->getElementW1(posInit)->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
          } else {
            if((m->getNameOfElement(posFinal) != "Hill") && ( m->getNameOfElement(posFinal) != "Tree") && (m->getNameOfElement(posFinal) != "Water")&&(m->getNameOfElement(posFinal)!="")&&(m->getNameOfElement(posFinal)!="Lava2")){
              if(posInit != posFinal){
                if(p.isMineUnit(m->getNameOfElement(posFinal)) != true){
                  m->getElementW1(posInit)->attack(m->getElementW1(posFinal),numattack,p,p2,posFinal,m);
                }  else {
                  std::cout << "ce n'est pas ton unité 1" << '\n';
                }
              } else {
                std::cout << "Tu ne peux pas attaqué sur ta propre case" << '\n';
              }
            } else {
              if(distance<=this->_movement){                                                                                                                                                                                                      // si on a assez de deplacement on se deplace
                if(distance != 0){
                  Unit *u = new Unit();
                  int mouvementdefault = m->getElementW1(posInit)->getDefault();
                  m->setElementW1(posFinal,this);                                                                                                                                                                                                 // je  crée un unité vide que je mettrais a l'ancienne position qui mettrat avec la fonction "setElementW1" vide dans le tableaux
                  m->setElementW1(posInit,u);
                  m->getElementW1(posFinal)->setMovement(m->getElementW1(posFinal)->getMovement()-(distance));
                  this->setPosition(posFinal);
                  m->getElementW1(posFinal)->setDefault(mouvementdefault);
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
          }//fin else
        }//fin else
      } //fin else
    } else {
      std::cout << "Ce n'est pas ton unité 2 " << '\n';
    }

  }
}


/****************************************/

/*** Methode Putties ***/

Putties::Putties(){                                                                                     // CONSTRUCTEUR PUTTIES PAR DEFAULT

  this->setName("Putties");
  this->setHealthPoints(50); // les HP du Putties
  this->setPrice(5);  // Le prix du Putties
  this->setMovement(2);
  _primaryWeapon = new Weapon("fist",5,1,20);
  _defaultMovement = this->getMovement();
}


Putties::Putties(int hp,int mvmt,int price,Weapon *wp,std::string nom){                                  // CONSTREUR PUTTIES
  this->setName("Putties");
  this->setHealthPoints(hp);
  this->setMovement(mvmt);
  this->setPrimaryW(wp);
  this->setPrice(price);
  this->_defaultMovement = this->getMovement();
}

Putties::~Putties(){                                                                                    // DESTRUCTEUR PUTTIES

}


  void Putties::attack(Unit* u,int W ,Player& p,Player& p2,Position posFinal,Map* m){                   // Fonction d'attaque de l'unité Putties
  //  std::cout << "IN FCT PUTTIES ATTAQUE" << '\n';
Position posInit = this->_pos;
int distance = Distance(posInit,posFinal);                                                              // je recupere la distance entre la position de l'unité attaquante et la position à attaquer
//std::cout << "Ton arme a "<<this->_primaryWeapon->getAttackRange()<<" de portée et tu attaque a "<<distance << '\n';
  if(W == 1){                                                                                           // si c'est l'attaque numero 1
    if(p.getEnergy()>=((this->_primaryWeapon)->getCost())){                                              // alors si on a assez d'energie
      if(distance <= (this->_primaryWeapon)->getAttackRange()) {                                        // alors si on a assez de portée
        u->setHealthPoints(u->getHealthPoints()-this->getPrimaryW()->getStrengh());                     // on attaques, on enleve un nombre de point de vie egale a la force du numero de l'arme
        p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        if(u->getHealthPoints()<=0){                                                                    // si l'unité est morte on la supprimes
            Unit *dead = new Unit;
            m->setElementW1(posFinal,dead);
            p2.removeUnit(*u);                                                                          // on l'enleve du tableaux des unités alliées
          }
      } else {
        std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
  }
}

/*************************/




/*** CLASS POWERRANGER ***/


PowerRanger::PowerRanger(){                                                                               // Constructeur par default powerranger

}

PowerRanger::PowerRanger(std::string color){                                                              // constructeur POWERRANGER suivant sa couleurs
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

PowerRanger::~PowerRanger(){                                                                            // DESTRUCTERUR POWERRANGER

}


/** GETTER **/

std::string PowerRanger::getColor()const{
  return(this->_color);
}

int PowerRanger::getDefault()const{
  return(this->_defaultMovement);
}

bool PowerRanger::getCapacityRobot()const{
  return(this->_capacityRobot);
}

bool PowerRanger::getCapacityWeapon()const{
  return(this->_capacityWeapon);
}

/** SETTER **/

void PowerRanger::setColor(std::string color){
  this->_color = color;
}

void PowerRanger::setCapacityRobot(bool cap){
  this->_capacityRobot = cap;
}

void PowerRanger::setCapacityWeapon(bool cap){
  this->_capacityWeapon = cap;
}

/** METHODE **/

  void PowerRanger::attack(Unit* u,int W ,Player& p,Player& p2,Position posFinal,Map* m){                           // fonction d'attaque powerranger
    //std::cout << "IN FCT POWERRANGER ATTAQUE" << '\n';
    if(u != NULL){

      std::cout << "HP AVANT :"<<u->getHealthPoints() << '\n';
    }
    Position posInit = this->_pos;
  //  std::cout << "POS INIT : "<<posInit<<std::endl<<"Pos final :"<<posFinal << '\n';
    int distance = Distance(posInit,posFinal);
  if(W != -1){
    if(W == 1){
      if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
        if(distance <= (this->_primaryWeapon)->getAttackRange()){
          u->setHealthPoints(u->getHealthPoints()-this->_primaryWeapon->getStrengh());
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        } else {
          std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    }else if(W == 2) {
      if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){
        if((distance <= (this->_secondaryWeapon)->getAttackRange()) || (this->_secondaryWeapon->getAttackRange() ==-1)){
          if(this->getName() == "green"){
            //std::cout << "TEST AVANT TORNADODINO" << '\n';
            this->TornadoDino(m,p,posFinal);
            p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
          } else {
            u->setHealthPoints(u->getHealthPoints()-this->_secondaryWeapon->getStrengh());
            p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
          }
        } else {
          std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    } else if (W == 3){
      if(p.getEnergy()>=((this->_thirdWeapon)->getCost())){
          this->Transformation(m,p);
          p.setEnergy(p.getEnergy()-(this->_thirdWeapon)->getCost());
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    } else if(W == 4) {
      if(p.getEnergy()>=((this->_fourthWeapon)->getCost())){
        this->CheaterWeaponOn(m);
        if(this->getCapacityWeapon()==true){
          if(distance <= (this->_fourthWeapon)->getAttackRange()){
            u->setHealthPoints(u->getHealthPoints()-this->_fourthWeapon->getStrengh());
            p.setEnergy(p.getEnergy()-(this->_fourthWeapon)->getCost());
          } else {
            std::cout<<"Tu n'as pas la portée necessaire"<<std::endl;
          }
        } else {
          std::cout<<"Tu n'as pas la capacité disponible"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    } else {
    std::cout << "Tu n'as pas selectionné d'attaque" << '\n';
    }

  } else {
    std::cout << "Tu n'as pas selectionné d'attaque" << '\n';
  }
          if(u != NULL){
            if(u->getHealthPoints()<=0){
              Unit *dead = new Unit;
              m->setElementW1(posFinal,dead);
              p2.removeUnit(*u);
            }
            std::cout << "HP APRES : "<<u->getHealthPoints() << '\n';

          }

}

void PowerRanger::TornadoDino(Map* m,Player& p,Position pos){                                                                                                                                                           // Fonction qui invoque un finosaure totalement inutile dans la partie
  if((m->getNameOfElement(pos)=="Tree")||(m->getNameOfElement(pos)=="Hill")||(m->getNameOfElement(pos)=="Water")||(m->getNameOfElement(pos)=="Lava2")||(m->getNameOfElement(pos)=="Lava2")){
    Unit *d = new Dino;
    m->setElementW1(pos,d);
    p.pushUnit(d);


  }
}

void PowerRanger::BeTogether(Map *m,Position pos,bool* hor, bool* ver){                                                   // fonction qui regarde avec la position donnée si dans l'axe X ou l'axe Y si 5 powerranger sont aligné
  int i = 0;
  int k = 0;
  //std::cout<<"IN FCT BETOGETHER"<<std::endl;
  //std::cout<<"premiere pos p.X "<<pos.getX()<<" p.Y : "<<pos.getY()<<std::endl;
  Position currentPos;
  currentPos.setY(pos.getY());
  //std::cout<<"TEST BOUCLE 1"<<std::endl;
  for(int j =0;j<m->getSizeX();j++){
    currentPos.setX(j);
    //std::cout<<"posX : "<<currentPos.getX()<<std::endl;
    //std::cout<<"posY : "<<currentPos.getY()<<std::endl;
    if(m->getElementW1(currentPos) != NULL){
      if((m->getElementW1(currentPos)->getName()!="Putties")&&(m->getElementW1(currentPos)->getName()!="Zedd")){
        i++;
      }
    }
  }
  currentPos.setX(pos.getX());
  //std::cout<<"TEST BOUCLE 2"<<std::endl;
  for(int j =0;j<m->getSizeY();j++){
    currentPos.setY(j);
  //  std::cout<<"posX : "<<currentPos.getX()<<std::endl;
  //  std::cout<<"posY : "<<currentPos.getY()<<std::endl;
    if(m->getElementW1(currentPos)!= NULL){
      if((m->getElementW1(currentPos)->getName()!="Putties")&&(m->getElementW1(currentPos)->getName()!="Zedd")){
        k++;
      }
    }
  }
  //std::cout << "I : "<<i << std::endl;
//  std::cout << "K : "<<k << std::endl;
  if(i>=5){                                                                                                                                                                   // si c'est le cas on renvois l'axe en question
    (*hor)=true;
  } else if(k>=5){
    (*ver)=true;
  } else {
    (*hor)=false;
    (*ver)=false;
  }
  //std::cout<<"TEST FIN BOUCLE BETOGETHER"<<std::endl;
}



void PowerRanger::Transformation(Map *m,Player&p){                                                                                                                            // fonction qui transporte les powerranger ( sauf le verts) dans un robotPR
  //std::cout << "DEBUT DCT TRANSFOR" << '\n';                                                                                                                                  // recherche dans l'axe retourné par "betogether"
  Position pos = this->_pos;                                                                                                                                                  // met les powerranger dans un tableaux pour ne pas les effacé
  Position currentPos;                                                                                                                                                        // met a la place un robot PR
  Unit *u = new Unit;
  Position posred;
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
          if(m->getElementW1(currentPos)!=NULL){
            if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
              if(m->getNameOfElement(currentPos) == "red"){
                posred = currentPos;
              }
              m->setInTab(*(m->getElementW1(currentPos)));
              m->setElementW1(currentPos, u);
            }
          }
        }
        //std::cout << "MIDDLE FCT TRANSFOR" << '\n';
      } else if ( ver == true){
        currentPos.setX(pos.getX());
        for(int j=0;j<m->getSizeY();j++){
          currentPos.setY(j);
          if(m->getElementW1(currentPos)!=NULL){
            if((m->getNameOfElement(currentPos)!="Putties")&&(m->getNameOfElement(currentPos)!="Zedd")&&(m->getNameOfElement(currentPos)!="green")){
              if(m->getNameOfElement(currentPos) == "red"){
                posred = currentPos;
              }
              m->setInTab(*(m->getElementW1(currentPos)));
              m->setElementW1(currentPos,u);
            }

          }
        }
      }
      if(this->getName() == "green"){
        m->setElementW1(posred,r);
        p.pushUnit((m->getElementW1(posred)));
      } else {
        m->setElementW1(pos,r);
        p.pushUnit((m->getElementW1(pos)));
      }
  }
  //std::cout << "FIN FCT TRANSFOR" << '\n';
}

void PowerRanger::CheaterWeaponOn(Map *m){                                                              // fonction qui active la capacité arme cheaté
  bool hor = false;
  bool ver = false;
  Position pos = this->_pos;
  BeTogether(m,pos,&hor,&ver);
  if((hor == true)||(ver == true)){
    this->_capacityWeapon = true;
  } else {
    this->_capacityWeapon = false;
  }
  //std::cout<<"TEST FIN FCT CHEATERWEAPONON"<<std::endl;
}


/******************************************************/


/*** class Dino ***/

Dino::Dino(){                                                                                   // constructeur DINO
    this->setName("TornadoDino");
    this->setHealthPoints(150);
    this->setMovement(3);
    _primaryWeapon = new Weapon("Tornado",0,0,50);
    this->_defaultMovement = this->getMovement();
}

Dino::~Dino(){                                                                                  // destructeur DINO

}

/**** CLASS ZEDD ***/


Zedd::Zedd(){                                                                                       // constructeur ZEDD
  _activeExpendNade = false;
  _primaryWeapon = new Weapon("Grenade",0,-1,100);
  _secondaryWeapon = new Weapon("Invocation",0,-1,50);
  _thirdWeapon = new Weapon("PuttiesCalling",0,-1,50);
  _fourthWeapon = new Weapon("ApocalypseHole",1200,0,100);
  setName("Zedd");
  setHealthPoints(5000);
  setPuttiesCalling(0);
  setInvocation(2);
  setApocalypseHole(0);
  apoon = false;
  //std::cout<<"ARME : "<<_thirdWeapon->getName()<<std::endl;
}

Zedd::~Zedd(){                                                                                    // DESTRUCTEUR ZEDD

}

/** GETTER **/

int Zedd::getActiveExpendNade()const{
  return(this->_activeExpendNade);
}

int Zedd::getInvocation()const{
  return(this->_invocation);
}

int Zedd::getPuttiesCalling()const{
  //std::cout << "TEST GET PUTTIESCALLING" << '\n';
  return(this->_puttiesCalling);
}

int Zedd::getApocalypseHole()const{
  return(this->_apocalypseHole);
}

bool Zedd::getApoon()const{
  return(this->apoon);
}

/** SETTER **/

void Zedd::setActiceExpendNade(int nade){
  this->_activeExpendNade = nade;
}

void Zedd::setInvocation(int invoc){
//  std::cout << "test set invoc" << '\n';
  this->_invocation = invoc;
}

void Zedd::setPuttiesCalling(int putties){
  //std::cout << "TEST SETPUTTINGCALLING" << '\n';
  this->_puttiesCalling = putties;
}

void Zedd::setApocalypseHole(int hole){
  this->_apocalypseHole = hole;
}

void Zedd::setApoon(bool ap){
  this->apoon = ap;
}

/** METHODE **/

void Zedd::attack(Unit* u,int W ,Player& p,Player& p2,Position posFinal,Map* m){             // fonction d'attaque pour ZEDD
  //std::cout << "IN FCT ZEDD ATTAQUE" << '\n';
  if(W != -1){
    if(W == 1){
      this->ThrowExtendNade(posFinal,m,p);
    } else if(W == 2){
      this->Invocation(posFinal,m,p);
    } else if(W == 3){
      this->PuttiesCalling(posFinal,m,p);
    } else if(W == 4){
      this->ApocalypseHole(m,p);
    }
  }else {
    std::cout << "Tu n'as pas selectionner d'arme" << '\n';
  }
}

void Zedd::EnableGrenade(Map* m){                                                             // fonction qui regarde si les points de vie d'un serviteur sont en dessous de 40 et si c'estle cas permet l'utilisation de la grenade renforçante
  Position currentPos;
  for(int i = 0;i<m->getSizeX()/32;i++){
    for(int j=0;j<m->getSizeY()/32;j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m->getNameOfElement(currentPos)=="Putties"){
        if((m->getElementW1(currentPos))->getHealthPoints()<= 40){
          this->_activeExpendNade = true;
        }
      }
    }
  }
}


void Zedd::ThrowExtendNade(Position pos,Map *m,Player& p){                                    // utilisation de la grenade
//  std::cout << "TEST GRENADE" << '\n';                                                        // donne a l'unité plus de point de vie et d'attaque
    this->EnableGrenade(m);
  //  std::cout << "/* message */" << '\n';
    if(p.getEnergy()>=(getPrimaryW()->getCost())){
    //  std::cout << "/* message2 */" << '\n';
      if(this->getActiveExpendNade()==true){
      //  std::cout << "/* message3 */" << '\n';
        if((m->getNameOfElement(pos))=="Putties") {
        //  std::cout << "/* message4 */" << '\n';
          // std::cout << "Postition : "<<pos << '\';
          // m->getElementW1(pos).setHealthPoints(1500);
          //Weapon *wp = new Weapon("Big attack",200,1,60);
          //m->getElementW1(pos).setPrimaryW(wp);
          Weapon *wp = new Weapon("BIGTTACK",200,1,50);
          Unit *u = new Putties(1500,3,100,wp);
          u->setPosition(pos);
          m->setElementW1(pos,u);
          //std::cout<<"Nom arme : "<<m->getElementW1(pos)->getPrimaryW()->getName()<<std::endl;
          // m->getElementW1(pos).getPrimaryW()->setName("BIG ATTACK");
          // m->getElementW1(pos).getPrimaryW()->setStrengh(200);
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        //  std::cout << "/* message5 */" << '\n';
        //  std::cout << "HP : "<<m->getElementW1(pos)->getHealthPoints() << '\n';
        //  std::cout << "/* message6 */" << '\n';
        //  std::cout << "FORCE : "<<m->getElementW1(pos).getPrimaryW()->getStrengh() << '\n';
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


void Zedd::Invocation(Position pos, Map *m,Player& p){                                                          // utilisation de la fonction dinvocation
    if(p.getEnergy()>((this->_secondaryWeapon)->getCost())){                                                    // suivant le decors ou on invoque une creature differente
      if(this->getInvocation() == 0){                                                                           // et la met dans le tableaux d'unité du joueur
        if(m->getElementW1(pos)==NULL){
          int hp;
          int mvmt;
          Weapon *wp;
		std::string name;
          if(m->getElementW2(pos).getName()=="Water"){
		  name = "Octopus";
		  hp = 250;
            mvmt = 1;
            wp = new Weapon("Canon a eau",150,1,50);
          } else if (m->getElementW2(pos).getName()=="Hill"){
		  name = "Dragoon";
            hp = 300;
            mvmt = 3;
            wp = new Weapon("Lancer de terre",120,3,50);
          } else if(m->getElementW2(pos).getName()=="Tree"){
		  name = "Haunted Tree";
            hp = 150;
            mvmt = 4;
            wp = new Weapon("Lancer de tronc",210,4,60);
          }
          Unit *u = new Putties(hp,mvmt,60,wp);
          u->setPosition(pos);
		u->setName(name);
          m->setElementW1(pos,u);




          p.pushUnit((m->getElementW1(pos)));
          p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
          this->setInvocation(5);                                  // WARNING WARNING WARNING
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



void Zedd::PuttiesCalling ( Position pos, Map* m,Player& p){                                                                                                                // fonction d'appel des putties
//  std::cout << "IN FCT PUTTIESCALLING" << std::endl;
  //std::cout << "Putties : " <<this->_puttiesCalling<< '\n';                                                                                                                      // je prends la position ou on veut les invoqué je regarde si autour de la position il n'y a rien d'autre et si c'est le cas je les invoques
//  std::cout << "name : "<<getThirdW()->getName() << '\n';
    if(p.getEnergy()>=(getThirdW()->getCost())){
    //  std::cout << "/* message */" << '\n';
      if(this->_puttiesCalling==0){
        Position p1 = pos;
        p1.setY(pos.getY()+1);
        Position p2 = pos;
        p2.setY(pos.getY()-1);
        Position p3 = pos;
        p3.setX(pos.getX()+1);
        Position p4 = pos;
        p4.setX(pos.getX()-1);
      //  std::cout << "/* message2 */" << '\n';
        if((m->isOnMap(pos))&&(m->isOnMap(p1))&&(m->isOnMap(p2))&&(m->isOnMap(p3))&&(m->isOnMap(p4))){
          if((m->getElementW1(pos)==NULL)&&(m->getElementW1(p1)==NULL)&&(m->getElementW1(p2)==NULL)&& (m->getElementW1(p3)==NULL)&&(m->getElementW1(p4)==NULL)){
          //  Weapon *wp = new Weapon("Default",5,1,20);
        //  std::cout << "/* message3 */" << '\n';
            Unit *n1 = new Putties;
            n1->setPosition(pos);
            Unit *n2 = new Putties;
            n2->setPosition(p1);
            Unit *n3 = new Putties;
            n3->setPosition(p2);
            Unit *n4 = new Putties;
            n4->setPosition(p3);
            Unit *n5 = new Putties;
            n5->setPosition(p4);
            // n1->setMovement(3);
            // n1->setDefault(3);
            m->setElementW1(pos,n1);
            // m->getElementW1(pos)->setDefault(3);
            m->getElementW1(pos)->setPosition(pos);
            p.pushUnit(m->getElementW1(pos));
            //
            m->setElementW1(p1,n2);
            // m->getElementW1(p1)->setDefault(3);
            m->getElementW1(p1)->setPosition(p1);
            p.pushUnit(m->getElementW1(p1));
            //
            m->setElementW1(p2,n3);
            // m->getElementW1(p2)->setDefault(3);
            m->getElementW1(p2)->setPosition(p2);
            p.pushUnit(m->getElementW1(p2));
            //
            m->setElementW1(p3,n4);
            // m->getElementW1(p3)->setDefault(3);
            m->getElementW1(p3)->setPosition(p3);
            p.pushUnit(m->getElementW1(p3));
            //
            m->setElementW1(p4,n5);
            // m->getElementW1(p4)->setDefault(3);
            m->getElementW1(p4)->setPosition(p4);
            p.pushUnit(m->getElementW1(p4));
            //
          //  std::cout << "/* message4 */" << '\n';
            p.setEnergy(p.getEnergy()-(this->_thirdWeapon)->getCost());
            this->setPuttiesCalling(4);
            m->getElementW1(this->_pos)->setPuttiesCalling(4);
            m->getElementW1(pos)->setDefault(3);
            //std::cout << "DEFAULT POSITION GETdEFAIULT : " <<m->getElementW1(pos)->getDefault()<< std::endl;
            //std::cout << "TEST A LA FIN DE PUTTIESCALLING" << std::endl;
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


void Zedd::ApocalypseHole(Map *m,Player& p){                                                                // fonction de l'attaque apocalypse
                                                                                                            // si je la lance pour la premieres fois, la position sur laquelle se trouve ZEDD devient de la lave
  //static int count = 0;                                                                                   // si ce n'est pas la premiere fois, toute les cases autours d'une case lave se transforme en lave aussi
                                                                                                            // si une unité enemies a zedd touche la lave, elle pers 1200 point de vie
  if(this->apoon == false ){
      if(p.getEnergy() >=((this->_fourthWeapon)->getCost())){
        if(this->apoon == false){
          Scenery *s = new Lava;
          s->setName("Lava2");
          m->setElementW2(this->getPosition(),*s);
        //  std::cout << "map : " <<m->getElementW2(this->getPosition()).getName()<< std::endl;
          p.setEnergy(p.getEnergy()-(this->_fourthWeapon)->getCost());
          //count++;
          this->apoon = true;
        }
      }else {
        std::cout<<"You don't have enough energy"<<std::endl;
      }
    } else {
      //std::cout << "/* message5 */" << std::endl;
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

RobotPR::RobotPR(){                                                                                       // constructeur robotPR
  this->setArmor(1000);
  this->setHealthPoints(1000);
  this->setName("RobotPR");
  _primaryWeapon = new Weapon("Fist",300,1,60);
  _secondaryWeapon = new Weapon("Sword",600,3,100);
  _thirdWeapon = new Weapon("TURTLE",0,-1,100);
  this->setMovement(5);
  this->_defaultMovement = this->getMovement();
}

RobotPR::~RobotPR(){                                                                                        // destructeur robotPR

}

int RobotPR::getArmor()const{
  return( this->_armor);
}

void RobotPR::setArmor(int armor){
  this->_armor = armor;
}



void RobotPR::TransformationTurtle(Map* m,Player& p,Player& p2,Position pos){                               // transformation identique a la transformation du powerranger en robotpr
  if(p2.getSizeOwnUnit() > 15){
    if(m->getNameOfElement(pos)=="RobotPR"){
      //std::cout << "/* message */" << std::endl;
      Unit *tt = new TurtleTank;
      m->setInTab(*m->getElementW1(pos));
      m->setElementW1(pos,tt);
      p.pushUnit(m->getElementW1(pos));
    }

  } else {
    std::cout << "Pas assez de monde pour activé le robot turtle" << '\n';
  }
}

void RobotPR::attack(Unit* u,int W ,Player& p,Player& p2,Position posFinal,Map* m){                           // fonction attaque du robot pR
    //std::cout << "IN FCT ROBOTPR ATTACK" << '\n';
  Position posInit = this->_pos;
  int distance = Distance(posInit,posFinal);
  if(W != -1){
    if(W ==  1){
      if(p.getEnergy()>((this->_primaryWeapon)->getCost())){
        if(distance <= (this->_primaryWeapon)->getAttackRange()){
          u->setHealthPoints(u->getHealthPoints()-this->getPrimaryW()->getStrengh());
          p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
        } else {
          std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    } else if (W == 2){
      if(p.getEnergy()>=((this->_secondaryWeapon)->getCost())){
        if(distance <= (this->_secondaryWeapon)->getAttackRange()){
          u->setHealthPoints(u->getHealthPoints()-this->_secondaryWeapon->getStrengh());
          p.setEnergy(p.getEnergy()-(this->_secondaryWeapon)->getCost());
        } else {
          std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
        }
      } else {
        std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
      }
    } else if(W == 3){
      if(p.getEnergy() >= (this->_thirdWeapon->getCost())){
        this->TransformationTurtle(m,p,p2,posInit);
      }
    }
    if(u != NULL){
      if(u->getHealthPoints()<= 0){
        Unit * u = new Unit;
        m->setElementW1(posFinal,u);
        p2.removeUnit(*u);
      }
    }

  } else {
    std::cout << "aucune attaque selectionné" << '\n';
  }
}


/*************************************************/


/*** TurtleTank ***/

TurtleTank::TurtleTank(){                                                                               // constructeur turtletank
    setHealthPoints(10000);
    setArmor(10000);
    setName("TurtleTank");
    _primaryWeapon = new Weapon("Fatality",10000,30,100);
    setMovement(5);
    this->_defaultMovement = this->getMovement();
}

TurtleTank::~TurtleTank(){                                                                              // destructeur turtletank

}

  void TurtleTank::attack(Unit* u,int W ,Player& p,Player& p2,Position posFinal,Map* m){                 // fonction attaque du robot pr
  Position posInit = this->_pos;
  int distance = Distance (posInit,posFinal);
    if(p.getEnergy()>=((this->_primaryWeapon)->getCost())){
      if(distance <= (this->_primaryWeapon)->getAttackRange()){
        u->setHealthPoints(u->getHealthPoints()-this->getPrimaryW()->getStrengh());
        p.setEnergy(p.getEnergy()-(this->_primaryWeapon)->getCost());
      } else {
        std::cout<<"Tu n'as pas la portee necessaire"<<std::endl;
      }
    } else {
      std::cout<<"Tu n'as pas l'energie necessaire"<<std::endl;
    }
    if(u->getHealthPoints()<= 0){
      Unit * u = new Unit;
      m->setElementW1(posFinal,u);
      p2.removeUnit(*u);
    }

}
