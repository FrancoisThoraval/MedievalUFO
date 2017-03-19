#include "unit.hpp"

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
void Zedd::Invocation(Position pos, Map *m){
  if(this->getInvocation() == 0){
    if(m.getElementW1(pos)!= NULL){
        int strengh;
        int hp;
        int range;
        int mvmt;
        Weapon *wp;
        if((m.getElementW2(pos).getName()=="Water"){
          strengh = 60;
          hp = 250;
          range = 1;
          mvmt = 1;
          wp = new Weapon("Canon a eau",150,1,50);
        } else if (m.getElementW2(pos).getName()=="Hill"){
                  strengh = 70;
                  hp = 300;
                  range = 3;
                  mvmt = 3;
                  wp = new Weapon("Lancer de terre",120,3,50);
                } else if(m.getElementW2(pos).getName()=="Tree"){
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
