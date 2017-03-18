#include "game.hpp"
#include <iostream>
Game::Game(int x, int y){
     _gameState = 0; //Initialization
     _xWindow = x;
     _yWindow = y;
     _isFullScreen = false;
}

Game::~Game(){

}

void Game::start(){
     if (_gameState != 0)
          return;

     _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Default);
     _gameState = 2;

     while (!isExiting()) {
          gameLoop();
     }

     _window.close();
}

bool Game::isExiting(){
     if (_gameState == 5) {
          return true;
     }else
          return false;
}

void Game::gameLoop(){
     sf::Event currentEvent;
     while (_window.pollEvent(currentEvent)) {
          if (currentEvent.type == sf::Event::KeyReleased) {
               if (currentEvent.key.code == sf::Keyboard::F) {
                    std::cout << "Hai premuto F" << '\n';
                    if (_isFullScreen) {
                         _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Default);
                         _isFullScreen = false;
                    }else{
                         _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Fullscreen);
                         _isFullScreen = true;
                    }

               }
          }
          switch (_gameState) {
               case 2 : {
                    showSpashScreen();
               break;
               }
               case 3: {
                    showMenu();
                    break;
               }
               case 4 : {
                    _window.clear(sf::Color(0,0,0));
                    _window.display();
                    if (currentEvent.type == sf::Event::Closed) {
                         _gameState = 5; //End
                    }
                    if(currentEvent.type == sf::Event::KeyPressed)
                    {
                        if(currentEvent.key.code == sf::Keyboard::Escape){
                         showMenu();
                         }
                    }
               break;
               }
               case 5 : {
                    _window.close();
               }
          }
     }
}

void Game::showSpashScreen(){
     SplashScreen s;
     s.show(_window);
     _gameState = 3;
}


void Game::showMenu(){
     Menu m;
     m.show(_window);
     m.handleClick(_window);
     std::cout << "here in the game.cpp: choice: "<< m.getMenuChoice() << '\n';
     switch (m.getMenuChoice()) {
          case 1: _gameState = 4;
               break;
          case 2: _gameState = 5;
               break;
     }
     if (_gameState == 4) {
          std::cout << "Si parte ! " << '\n';
     }else if(_gameState == 5){
          std::cout << "Adio amico !" << '\n';
     }
}
