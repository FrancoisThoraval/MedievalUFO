#include "element.hpp"

/*** Methode Element ***/

Element::Element(){

}

Element::~Element(){

}

Position Element::getPosition()const{
  return(this->_pos);
}

Element Element::getElementOnPos(Position pos){
  return(*this);
}

void Element::setElementPosition(Position pos){

}


//std::string Element::getName(){

//}

/************************************************/

/*** Methode Position ***/

Position::Position(){

}

Position::Position(int x,int y){
     setX(x);
     setY(y);
}

Position::~Position(){

}

int Position::getX()const{
  return(this->_x);
}

int Position::getY()const{
  return(this->_y);
}

void Position::setX(int x){
  this->_x = x;
}

void Position::setY(int y){
  this->_y = y;
}

/********************************************************/
