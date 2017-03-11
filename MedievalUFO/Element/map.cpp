#include "map.hpp"


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    _world1 = new Element* [_sizeX];
    _world2 = new Element* [_sizeX];
    for(int i =0; i <_sizeY;i++){
        _world1[i]= new Element[_sizeY];
        _world2[i]= new Element[_sizeY];
    }
    _scene = new QGraphicsScene();
    _view = new QGraphicsView(_scene);
}

Map::~Map(){
    for(int i =0; i <_sizeY;i++){
        delete _world1[i];
        delete _world2[i];
    }
    delete _world1;
    delete _world2;
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

    QBrush brush;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    rect->setBrush(brush);
    this->_scene->addItem(rect);
    this->_view->show();
}

void Map::drawWorld(){
    for(int i = 0; i< this->_sizeX; i++){
        for(int j = 0; j< this->_sizeY; j++){
            createTile(i,j);
        }
    }
}

/****************************************/
