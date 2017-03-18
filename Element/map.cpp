#include "map.hpp"


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    // _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    for(int i =0; i <_sizeX;i++){
     //    _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
}

Map::~Map(){
    for(int i =0; i <_sizeY;i++){
     //    delete _world1[i];
        delete _world2[i];
    }
    // delete _world1;
    delete _world2;
}

Unit Map::getElementW1(Position pos)const{
  return(this->_world1[pos.getX()][pos.getY()]);
}

void Map::setElementW1(Position pos,Unit u){
  this->_world1[pos.getX()][pos.getY()]=u;
}

void Map::setElementW2(Position pos,Scenery u){
    this->_world2[pos.getX()][pos.getY()]=u;
  }

Scenery Map::getElement(Position pos)const{
    return(this->_world2[pos.getX()][pos.getY()]);
}

std::string Map::getNameOfElement(Position pos)const{
    return(this->getElementW2(pos).getName());
}


void Map::setElement(Position pos,Element elt){

}


//  Idée: On a une matrice world2 qui contient tout les éléments de la map
//  Même chose pour world1.
//  Lorsqu'on affiche la map, si world1[x,y] = "vide", alors on affiche world2, sinon on affiche world1.
void Map::createTile(int x, int y, sf::RenderWindow &window){

     Position P;
     P.setX(x);
     P.setY(y);
     std::cout << "hello2" << '\n';
     if(this->getNameOfElement(P) == "Tree"){

     }else if(this->getNameOfElement(P) == "Water"){
          std::cout << "hello 3" << '\n';
          if (!this->texture.loadFromFile("./Textures/water.png"))
          {
               std::cerr << "Texture not loaded" << '\n';
          }
          this->sprite.setTexture(this->texture);
          this->sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

          window.draw(this->sprite);

     }else if(this->getNameOfElement(P) == "Hill"){

     }

}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "hello" << '\n';
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
            createTile(i,j, window);
        }
    }
}

/****************************************/
