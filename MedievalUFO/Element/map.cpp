#include "map.hpp"
#include <typeinfo>
#include <iostream>
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


//  Idée: On a une matrice world2 qui contient tout les éléments de la map
//  Même chose pour world1.
//  Lorsqu'on affiche la map, si world1[x,y] = "vide", alors on affiche world2, sinon on affiche world1.
void Map::createTile(int x, int y){
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,TILESIZEX,TILESIZEY);
    rect->setPos(x*TILESIZEX,y*TILESIZEY);
    QBrush brush;
    try {


    if((this->_world2[x][y]).Tree::getName()  == "Tree"){
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);
    }else if(reinterpret_cast<Tree&>((this->_world2[x][y])).getName() == "Water"){
        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
    }else if(reinterpret_cast<Tree&>((this->_world2[x][y])).getName() == "Hill"){
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);
    }
    } catch (std::bad_cast& bc){
        std::cerr<<"test : "<<bc.what()<<std::endl;
    }

    rect->setBrush(brush);
    this->_scene->addItem(rect);
    this->_view->show();
}

void Map::drawWorld(){
    for(int i = 0; i< this->_sizeX; i++){
        for(int j = 0; j< this->_sizeY; j++){
            if(j < 5){
//                Element *e;
//                Tree *t = dynamic_cast<Tree*>(e) ;
                Element *t = new Tree;

                _world2[i][j] = *t;
                //std::cout <<
            }
           if(j>= 5){
               Element *w = new Water;
               _world2[i][j] = *w;
           }
            if(i>= _sizeX-3){
                Element *h = new Hill;
                _world2[i][j] = *h;
            }
            createTile(i,j);
        }
    }
}

/****************************************/
