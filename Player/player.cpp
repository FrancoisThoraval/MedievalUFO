#include "player.hpp"

Player::Player(){
    this->_energy = 100;
    this->_lost = false;
    this->_ownUnit = new Unit [5];
}

Player::Player(std::string name,int value){
    this->_energy = 100;
    this->_lost = false;
    this->_name = name;
    this->_ownUnit = new Unit [5];
    this->_value = value;
}

Player::~Player(){

}

int Player::getValue()const{
     return(this->_value);
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

void Player::setValue(int value){
     this->_value = value;
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
     int i = 0;
     while (_ownUnit[i].getName() != "") {
          i++;
     }
     _ownUnit[i] = u;
}

void Player::showUnitOwned(){
     for (int i = 0; i < 5; i++) {
          std::cout << "["<< _ownUnit[i].getName() << "] -> ";
          std::cout << _ownUnit[i].getMovement() << '\n';
     }
}
/*
void Player::EndOfTurn(Map *m){
  this->_energy = 100;
  ResetMovement(m);
}

void Player::ResetMovement(Map *m){
  Position currentPos;
  for(int i=0;i<m->getSizeX();i++){
    for(int j=0;j<m->getSizeY();j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m->getNameOfElement(currentPos)!=""){
        (m->getElementW1(currentPos)).setMovement((m->getElementW1(currentPos)).getDefault());
      }
    }
  }
}
*/
