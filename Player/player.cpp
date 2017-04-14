#include "player.hpp"

Player::Player(){
    this->_energy = 100;
    this->_lost = false;
    this->_ownUnit = new Unit [1];
    this->_sizeOwnUnit = 0;
    this->_isPlaying = false;
    this->_sizeOwnMax = 0;
}

Player::Player(std::string name,bool value){
    this->_energy = 100;
    this->_lost = false;
    this->_name = name;
    this->_ownUnit = new Unit [1];
    this->_sizeOwnMax = 0;
    this->_sizeOwnUnit = 0;
    this->_isPlaying = value;
}

Player::~Player(){

}

bool Player::getWhosPlaying()const{
     return(this->_isPlaying);
}

int Player::getEnergy()const{
  return(this->_energy);
}

bool Player::getLost()const{
  return(this->_lost);
}

std::string Player::getName()const{
  return(this->_name);
}

void Player::setWhosPlaying(bool value){
      //std::cout<<"ENTER ON WHOSPLAYING"<<std::endl;
     this->_isPlaying = value;
}

void Player::setEnergy(int en){
  this->_energy = en;
}

void Player::setLost(bool butt){
  this->_lost = butt;
}

void Player::setName(std::string name){
  this->_name = name;
}

void Player::pushUnit(Unit &u){
    //int i = 0;
    std::cout << "/* message */" << std::endl;
     if(this->_sizeOwnUnit < this->_sizeOwnMax){
       _ownUnit[_sizeOwnUnit] = u;
       this->_sizeOwnUnit++;
     } else {
       Unit tab[_sizeOwnMax];
       for(int i =0; i<_sizeOwnMax;i++){
         tab[i]=_ownUnit[i];
       }
       delete[] _ownUnit;
       this->_ownUnit = new Unit[_sizeOwnMax +1];
       for(int i =0;i<_sizeOwnMax;i++){
         _ownUnit[i]=tab[i];
       }
       _ownUnit[_sizeOwnMax]=u;
       _sizeOwnMax++;
       _sizeOwnUnit++;
     }




    //  while (_ownUnit[i].getName() != "") {
    //       i++;
    //  }
    //  _ownUnit[i] = u;
    //  _sizeOwnUnit++;
}

int Player::getSizeOwnUnit()const{
  return(this->_sizeOwnUnit);
}

void Player::removeUnit(Unit &u){
     showUnitOwned();
     int i = 0;
     while ((i<_sizeOwnUnit)&&(u.getName()!=_ownUnit[i].getName())) {
          i++;
     }
     for (int j = i; j < _sizeOwnUnit; j++) {
          _ownUnit[i]=_ownUnit[i+1];
     }
     _sizeOwnUnit--;
     showUnitOwned();
     std::cout << "Have i lost ?" << getLost()<< '\n';
     std::cout << true << '\n';
}


bool Player::isMineUnit(const Unit u){
  bool rep = false;
  for(int i = 0;i<_sizeOwnUnit;i++){
    if(u.getName()==this->_ownUnit[i].getName()){
      rep = true;
    }
  }
  return(rep);
}

bool Player::isMineUnit(const std::string name){
  bool rep = false;
  for(int i = 0;i<_sizeOwnUnit;i++){
    if(name==this->_ownUnit[i].getName()){
      rep = true;
    }
  }
  return(rep);
}

void Player::showUnitOwned(){
     for (int i = 0; i < _sizeOwnUnit; i++) {
          std::cout << "["<< _ownUnit[i].getName() << "] -> ";
          std::cout << _ownUnit[i].getMovement() << '\n';
          std::cout<<" : "<<_ownUnit[i].getDefault()<<std::endl;
     }
}

Unit& Player::getUnit(int pos){
  return(this->_ownUnit[pos]);
}

void Player::EndOfTurn(Map *m){
     this->_energy = 100;
     ResetMovement(m);
}

void Player::ResetMovement(Map *m){
  Position currentPos;
  std::cout << "DEBUT RESETMSVMT" << '\n';
  for(int i=0;i<m->getSizeX();i++){
    for(int j=0;j<m->getSizeY();j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m->getElementW1(currentPos)!=NULL){
      // if((m->getNameOfElement(currentPos)!="Hill")&&(m->getNameOfElement(currentPos)!="Water")&&(m->getNameOfElement(currentPos)!="Tree")&&(m->getNameOfElement(currentPos)!="")&&(m->getNameOfElement(currentPos)!="Lava2")){
        (m->getElementW1(currentPos))->setMovement((m->getElementW1(currentPos))->getDefault());
        std::cout<<"DEFAULT : "<<m->getElementW1(currentPos)->getDefault()<<std::endl;
        std::cout<<"MVMT : "<<m->getElementW1(currentPos)->getMovement()<<std::endl;
      }
    }
  }
  std::cout << "FIN RESET MVMT" << '\n';
}

void Player::hasLost(){
     if (!getLost()) {
          if (_sizeOwnUnit == 0) {
               setLost(true);
          }
     }
}
