#include "map.hpp"


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    // _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    for(int i =0; i <_sizeX;++i){
     //    _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
}

Map::~Map(){
    for(int i =0; i <_sizeY;++i){
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

Scenery Map::getElementW2(Position pos)const{
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
void Map::createTile(int x, int y, sf::RenderWindow &window,sf::Texture t){
     sf::RectangleShape rectangle(sf::Vector2f(32, 32));
     Position P;
     P.setX(x);
     P.setY(y);
     std::cout << "Siam\' qui per creare un pezzo di mappa" << '\n';
     if(this->getNameOfElement(P) == "Tree"){
          // sf::Sprite s;
          // s.setTexture(t);
          // s.setTextureRect(sf::IntRect(x, y, 32, 32));
          rectangle.setFillColor(sf::Color::Green);
          rectangle.setPosition(x*32,y*32);
          window.draw(rectangle);
     }else if(this->getNameOfElement(P) == "Water"){
          std::cout << "Questo è dell'acqua" << '\n';
          // sf::Sprite s;
          // s.setTexture(t);
          // s.setTextureRect(sf::IntRect(x, y, 32, 32));
          rectangle.setFillColor(sf::Color::Blue);
          rectangle.setPosition(x*32,y*32);
          window.draw(rectangle);

     }else if(this->getNameOfElement(P) == "Hill"){
          // sf::Sprite s;
          // s.setTexture(t);
          // s.setTextureRect(sf::IntRect(x, y, 32, 32));
          rectangle.setFillColor(sf::Color::Red);
          rectangle.setPosition(x*32,y*32);
          window.draw(rectangle);
     }

}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "Iniziamo a creare la mappa" << '\n';
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){
               sf::Texture texture;

               // rectangle.setFillColor(sf::Color::Yellow);
               std::cout << "i: " << i << "| j :" << j << '\n';
               if(j < 5){
                    Scenery *t = new Tree;
                    _world2[i][j] = *t;
               }
               if(j>= 5){
                    Scenery *w = new Water;
                    _world2[i][j] = *w;
                    // texture.loadFromFile("./Textures/water.png");
               }
               if(i>= (_sizeX/32)-3){
                    Scenery *h = new Hill;
                    _world2[i][j] = *h;
               }
               createTile(i,j, window,texture);
          }
     }
     // for (int i = 0; i < 10; i++) {
     //      for (int j = 0; j < 10; j++) {
     //           std::cout << "i: " << i << "| j :" << j << '\n';
     //           sf::RectangleShape rectangle(sf::Vector2f(32, 32));
     //           rectangle.setFillColor(sf::Color::Yellow);
     //           if (i==3) {
     //                rectangle.setFillColor(sf::Color::Blue);
     //                /* code */
     //           }
     //           if (i==6) {
     //                rectangle.setFillColor(sf::Color::Green);
     //                /* code */
     //           }
     //           if (j==6) {
     //                rectangle.setFillColor(sf::Color::Red);
     //                /* code */
     //           }
     //           // s.setTexture(t);
     //           // s.setColor(sf::Color::Blue);
     //           // s.setTextureRect(sf::IntRect(0, 0, 32, 32));
     //           // s.setPosition(10+i*32,j*32);
     //           rectangle.setPosition(i*32,j*32);
     //           window.draw(rectangle);
     //      }
     // }
}

/****************************************/
