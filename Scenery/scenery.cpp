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
