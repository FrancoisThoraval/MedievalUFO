#include "scenery.hpp"

/*** Methode scenery ***/

Scenery::Scenery() {

}

Scenery::~Scenery(){

}

void Scenery::setName(string name){
  this->_name = name;
}

string Scenery::getName(){
  return(this->_name);
}


/*******************************/

/*** Methode Tree ***/

Tree::Tree(){
    _name = "Tree";
}

Tree::~Tree(){

}

/******************************************/

/*** Methode Water ***/

Water::Water(){
  _name = "Water";
}

Water::~Water(){

}

/*********************************************/

/*** Methode Hill ***/

Hill::Hill(){
  _name = "Hill";
}

Hill::~Hill(){

}

/********************************************/
