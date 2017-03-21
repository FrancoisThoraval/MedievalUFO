#include "map.hpp"

// A faire, appliquer les textures correctement
// Verification


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    for(int i =0; i <_sizeX;++i){
        _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
}

Map::~Map(){
     delete[] _world1;
     delete[] _world2;
}

Unit Map::getElementW1(Position pos)const{
  return(this->_world1[pos.getX()][pos.getY()]);
}

void Map::setElementW1(Position pos,Unit &u){
  this->_world1[pos.getX()][pos.getY()]=u;
}

void Map::setElementW2(Position pos,Scenery &u){
    this->_world2[pos.getX()][pos.getY()]=u;
  }

Scenery Map::getElementW2(Position pos)const{
    return(this->_world2[pos.getX()][pos.getY()]);
}

std::string Map::getNameOfElement(Position pos)const{
     if (this->getElementW1(pos).getName() == "") {
          return(this->getElementW2(pos).getName());
     }else
          return (this->getElementW1(pos).getName());
}


void Map::setElement(Position pos,Element* elt){

}


//  Idée: On a une matrice world2 qui contient tout les éléments de la map
//  Même chose pour world1.
//  Lorsqu'on affiche la map, si world1[x,y] = "vide", alors on affiche world2, sinon on affiche world1.
void Map::createTile(int x, int y, sf::RenderWindow &window,sf::Texture &t){
     sf::RectangleShape rectangle(sf::Vector2f(32, 32));
     Position P;
     P.setX(x);
     P.setY(y);
     std::cout << "Siam\' qui per creare un pezzo di mappa" << '\n';
     if (this->getNameOfElement(P) == "zedd") {

     }
     if (this->getNameOfElement(P) == "putties") {

     }
     if (this->getNameOfElement(P) == "red") {

     }
     if (this->getNameOfElement(P) == "blue") {

     }
     if (this->getNameOfElement(P) == "green") {

     }
     if (this->getNameOfElement(P) == "yellow") {

     }
     if(this->getNameOfElement(P) == "Tree"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(207, 282, 32, 32));
          // rectangle.setFillColor(sf::Color::Green);
          s.setPosition(x*32,y*32);
          window.draw(s);
     }else if(this->getNameOfElement(P) == "Water"){
          std::cout << "Questo è dell'acqua" << '\n';
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(886, 91, 32, 32));
          // rectangle.setFillColor(sf::Color::Blue);
          s.setPosition(x*32,y*32);
          window.draw(s);

     }else if(this->getNameOfElement(P) == "Hill"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(772, 625, 32, 32));
          // rectangle.setFillColor(sf::Color::Red);
          s.setPosition(x*32,y*32);
          window.draw(s);
     }

}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "Iniziamo a creare la mappa" << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){

               // rectangle.setFillColor(sf::Color::Yellow);
               std::cout << "i: " << i << "| j :" << j << '\n';
               if(j < 5){
                    Scenery *t = new Tree;
                    _world2[i][j] = *t;
               }
               if(j>= 5){
                    Scenery *w = new Water;
                    _world2[i][j] = *w;
               }
               if(i>= (_sizeX/32)-3){
                    Scenery *h = new Hill;
                    _world2[i][j] = *h;
               }
               createTile(i,j, window,texture);
          }
     }
}

/****************************************/

bool Map::isOnMap(Position pos){
     if(((pos.getX()<0)||(pos.getX()>_sizeX))&&((pos.getY()<0)||(pos.getY()>_sizeY))) {
          std::cerr << "You cannot access this position !" << '\n';
          return false;
     }else
          return true;
}

int Map::getSizeY(){return this->_sizeY;}
int Map::getSizeX(){return this->_sizeX;}
void Map::setSizeY(int y){this->_sizeY = y;}
void Map::setSizeX(int x){this->_sizeX = x;}

void Map::handleClick(sf::RenderWindow &window){
     sf::Event menuEvent;
     bool test = true;
     while (test) {
          while (window.pollEvent(menuEvent)) {
               if (menuEvent.type == sf::Event::EventType::MouseButtonPressed) {
                    if (_menuChoice == 0) {
                         _menuChoice = checkZone(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, _btnPlay);
                         test = false;
                    }
                    if (_menuChoice == 0) {
                         _menuChoice = checkZone(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, _btnExit);
                         test = false;
                    }
               }
          }
     }
}
