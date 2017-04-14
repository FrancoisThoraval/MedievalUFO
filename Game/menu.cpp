#include "menu.hpp"
#include <iostream>
void Menu::show(sf::RenderWindow &window){                                                                                                          //constructeur menu
     _menuChoice =0;
     window.clear(sf::Color(0,0,0));
     sf::Texture image;
     image.loadFromFile("./test.png");
     sf::Sprite sprite(image);

     _btnPlay.rect.top = 9;
     _btnPlay.rect.height = 80;
     _btnPlay.rect.left = 10;
     _btnPlay.rect.width = 200;
     _btnPlay.action = 1;

     _btnExit.rect.top = 10;
     _btnExit.rect.height = 80;
     _btnExit.rect.left = 579;
     _btnExit.rect.width = 200;
     _btnExit.action = 2;
     window.draw(sprite);
     window.display();
}

int Menu::checkZone(int x, int y, Button b){                                                                                                        // fonction qui montre ou on a clické
     std::cout << "testing: x="<< b.rect.left << " y= " <<b.rect.top << '\n';
     if(b.rect.contains(x,y)) {
          // std::cout << "choice: " <<getMenuChoice() << '\n';
          std::cout << "b is between: x="<< x<< " y= "<< y << '\n';
          return b.action;
     }
     return 0;
}

void Menu::handleClick(sf::RenderWindow &window){                                                                                                   // fonction qui gere l'evenement d'ou l'on a cliqué par rapport au menus
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
