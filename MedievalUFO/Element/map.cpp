#include "map.hpp"


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    for(int i =0; i <_sizeX;i++){
        _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
    _scene.setSceneRect(0,0,_sizeX,_sizeY);

    //_view.setScene(&_scene);
}

Map::~Map(){
    for(int i =0; i <_sizeY;i++){
        delete _world1[i];
        delete _world2[i];
    }
    delete _world1;
    delete _world2;
}

Scenery Map::getElement(Position pos)const{
    return(this->_world2[pos.getX()][pos.getY()]);
}

std::string Map::getNameOfElement(Position pos)const{
    return(this->getElement(pos).getName());
}


void Map::setElement(Position pos,Element elt){

}


//  Idée: On a une matrice world2 qui contient tout les éléments de la map
//  Même chose pour world1.
//  Lorsqu'on affiche la map, si world1[x,y] = "vide", alors on affiche world2, sinon on affiche world1.
void Map::createTile(int x, int y){
    CustomItem rect;
    rect.setRect(x*TILESIZEX,y*TILESIZEY,TILESIZEX,TILESIZEY);
    QBrush brush;
    Position P;
    P.setX(x);
    P.setY(y);
    if(this->getNameOfElement(P) == "Tree"){
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);
       // std::cout<<"c'est un : "<<this->getNameOfElement(P)<<std::endl;
    }else if(this->getNameOfElement(P) == "Water"){
        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
       //std::cout<<"c'est un : "<<this->getNameOfElement(P)<<std::endl;
    }else if(this->getNameOfElement(P) == "Hill"){
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);
      // std:: cout<<"c'est un : "<<this->getNameOfElement(P)<<std::endl;
    }
    rect.setBrush(brush);
    this->_scene.addItem(&rect);

}

void Map::drawWorld(){
    for(int i = 0; i< this->_sizeX; i++){
        for(int j = 0; j< this->_sizeY; j++){
            if(j < 5){
                    Scenery *t = new Tree;
                    _world2[i][j] = *t;
            }
            if(j>= 5){
                Scenery *w = new Water;
                _world2[i][j] = *w;
             }
            if(i>= _sizeX-3){
                Scenery *h = new Hill;
                _world2[i][j] = *h;
             }
            createTile(i,j);
        }
    }
    this->_view.setScene(&_scene);
    this->_view.show();
}

/****************************************/
