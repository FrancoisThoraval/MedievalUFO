#include "menu.hpp"
#include <iostream>
void Menu::show(sf::RenderWindow &window){
     _menuChoice =0;
     window.clear(sf::Color(0,0,0));
     sf::Texture image;
     image.loadFromFile("./test.png");
     sf::Sprite sprite(image);

     _btnPlay.rect.top = 0;
     _btnPlay.rect.height = 299;
     _btnPlay.rect.left = 0;
     _btnPlay.rect.width = 800;
     _btnPlay.action = 1;

     _btnExit.rect.top = 300;
     _btnExit.rect.height = 299;
     _btnExit.rect.left = 0;
     _btnExit.rect.width = 800;
     _btnExit.action = 2;
     window.draw(sprite);
     window.display();
}

int Menu::checkZone(int x, int y, Button b){
     if(b.rect.contains(x,y)) {
          std::cout << "choice: " <<getMenuChoice() << '\n';
          return b.action;
     }
     return 0;
}

void Menu::handleClick(sf::RenderWindow &window){
     sf::Event menuEvent;
     bool test = true;
     while (test) {
          while (window.pollEvent(menuEvent)) {
               if (menuEvent.type == sf::Event::MouseButtonPressed) {
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

int Menu::getMenuChoice(){
     return _menuChoice;
}
