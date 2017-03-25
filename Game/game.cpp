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

     _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Power Rangers - Ultimate Battle Simulator (Alpha)",sf::Style::Default);
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
          std::cout << "isFullscreen: "<< _isFullScreen << '\n';

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
                    Map m(800,500);
                    Ui ui;
                    _window.clear(sf::Color(0,0,0));
                    ui.drawUi(_window);
                    m.drawWorld(_window);
                    while (_gameState == 4) {
                         _window.display();
                         while (_window.pollEvent(currentEvent)) {
                              if (currentEvent.type == sf::Event::Closed) {
                                   _gameState = 5; //End
                              }
                              if(currentEvent.type == sf::Event::KeyPressed)
                              {
                                   std::cout << "Opening menu" << '\n';
                                   if(currentEvent.key.code == sf::Keyboard::Escape){
                                        showMenu();
                                   }

                                   if (currentEvent.key.code == sf::Keyboard::F) {
                                        std::cout << "Toggling fullscreen" << '\n';
                                        if (_isFullScreen) {
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Default);
                                             _isFullScreen = false;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }else{
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Fullscreen);
                                             _isFullScreen = true;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }

                                   }

                              }
                         }
                         m.handleClick(_window,currentEvent);
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
     switch (m.getMenuChoice()) {
          case 1: _gameState = 4;
               break;
          case 2: _gameState = 5;
               break;
     }
     if (_gameState == 4) {
          std::cout << "Starting game..." << '\n';
     }else if(_gameState == 5){
          std::cout << "Closing game" << '\n';
     }
}
