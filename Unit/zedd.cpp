#include "zedd.hpp"

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
  this->_invocation = invoc;
}

void Zedd::setPuttiesCalling(int putties){
  this->_puttiesCalling = putties;
}

void Zedd::setApocalypseHole(int hole){
  this->_apocalypseHole = hole;
}

void Zedd::ThrowExtendNade(Position pos,Map *m,Player& p){
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

/**** PAS SUR DE CELLE CI *****/
void Zedd::Invocation(Position pos, Map *m,Player& p){
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
          std::cout<<"Il y a deja quelque chose sur cette case"<<std::endl;
        }
  } else {
    std::cout<<"Tu ne peux pas encore utiliser cette capacite"<<std::endl;
  }
}


void Zedd::PuttiesCalling ( Position pos, Map* m,Player& p){
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
        Unit *n1 = new Putties(50,2,5,wp);
        m->setElementW1(pos,*n1);
        m->setElementW1(p1,*n1);
        m->setElementW1(p2,*n1);
        m->setElementW1(p3,*n1);
        m->setElementW1(p4,*n1);
        p.setEnergy(p.getEnergy()-(this->_thirdWeapon)->getCost());
        this->_puttiesCalling = 4;
      } else {
        std::cout<<"Il y'a deja quelque chose sur une des cases"<<std::endl;
      }
    } else {
      std::cout<<"Une des coordonnées est hors map"<<std::endl;
    }
  } else {
  std::cout<<"Sort pas disponible"<<std::endl;
  }
}


void Zedd::ApocalypseHole(Map *m,Player& p){

  static int count = 0;
  if(this->_apocalypseHole == 0){
    if(count == 0){
      m->getElementW2(this->_pos).setName("Lava2");
      p.setEnergy(p.getEnergy()-(this->_fourthWeapon)->getCost());
      count++;
    } else {
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

}
