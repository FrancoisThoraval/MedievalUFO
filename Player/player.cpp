#include "player.hpp"

Player::Player(){
    this->_energy = 100;
    this->_lost = false;
}

Player::~Player(){

}

int Player::getEnergy()const{
  return(this->_energy);
}

bool Player::getLost()const{
  return(this->_lost);
}

void Player::setEnergy(int en){
  this->_energy = en;
}

void Player::setLost(bool butt){
  this->_lost = butt;
}

void EndOfTurn(){
  this->_energy = 100;
}
