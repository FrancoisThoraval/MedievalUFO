#ifndef game_hpp
#define game_hpp

// #include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>
#include <Graphics.hpp>
#include <string>
#include "splashScreen.hpp"
#include "menu.hpp"

// _gameState  ->   0    =    Initialization
// _gameState  ->   1    =    Splash
// _gameState  ->   2    =    Pause
// _gameState  ->   3    =    Menu
// _gameState  ->   4    =    Playing
// _gameState  ->   5    =    End

class Game {
private:
     bool isExiting();
     void gameLoop();
     void showSpashScreen();
     void showMenu();
     int _gameState;
     sf::RenderWindow _window;
     int _xWindow;
     int _yWindow;
public:
     Game(int x, int y);
     ~Game();
     void start();

};

#endif
