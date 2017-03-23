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

std::string Player::getName()const{
  return(this->_name);
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

void Player::EndOfTurn(){
  this->_energy = 100;
}
