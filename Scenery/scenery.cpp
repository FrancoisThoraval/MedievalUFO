#include "scenery.hpp"

/*** Methode scenery ***/

Scenery::Scenery() {

}

Scenery::~Scenery(){

}

void Scenery::setName(std::string name){
  this->_name = name;
}

std::string Scenery::getName(){
  return(this->_name);
}


/*******************************/

/*** Methode Tree ***/

Tree::Tree(){
    this->setName("Tree");
}

Tree::~Tree(){

}

/******************************************/

/*** Methode Water ***/

Water::Water(){
  this->setName("Water");
}

Water::~Water(){

}

/*********************************************/

/*** Methode Hill ***/

Hill::Hill(){
  this->setName("Hill");
}

Hill::~Hill(){

}

/********************************************/

/*** Methode Lava ***/

Lava::Lava(){
  this->setName("Lava1");
  this->setTransformation(0);
}

Lava::~Lava(){

}

int Lava::getTransformation()const{
  return(this->_waitToTransform);
}

void Lava::setTransformation(int tr){
  this->_waitToTransform = tr;
}
/********************/
