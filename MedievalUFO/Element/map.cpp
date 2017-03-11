#include "map.hpp"

/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;

    for(int i = 0; i< this->_sizeX; i++){
        for(int j = 0; j< this->_sizeY; j++){
            this->_world2[i][j] = new Element;
        }
    }
}

Map::~Map(){

}

Element Map::getElement(Position pos)const{
  Element test; //A enlever c'etait juste pour compiler
  return(/*this->*/ test);   // POSITION
}

void Map::setElement(Position pos,Element elt){

}

void Map::createTile(int x, int y){
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,TILESIZEX,TILESIZEY);
    rect->setPos(x*TILESIZEX,y*TILESIZEY);
}

void Map::drawWorld(){
    for(int i = 0; i< this->_sizeX; i++){
        for(int j = 0; j< this->_sizeY; j++){
            createTile(i,j);
        }
    }
}

/****************************************/
