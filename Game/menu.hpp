#ifndef menu_hpp
#define menu_hpp

#include <SFML/Graphics.hpp>

// menuChoice -> 0 = Nothing
// menuChoice -> 1 = Play
// menuChoice -> 2 = Exit

class Button {
public:
     sf::Rect<int> rect;
     int action;
};

class Menu {
private:
     int _menuChoice;
     Button _btnExit, _btnPlay;
     sf::RenderWindow _window;
public:
     int checkZone(int,int,Button);
     void handleClick(sf::RenderWindow &);
     void show(sf::RenderWindow &);
     int getMenuChoice();
};

#endif
