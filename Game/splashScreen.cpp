#include "splashScreen.hpp"
#include <iostream>

void SplashScreen::show(sf::RenderWindow &window){
     sf::Texture image;
     if (!(image.loadFromFile("./splashScreen.png"))) {
          return;
     }
     window.clear(sf::Color(0,0,0));
     sf::Sprite sprite(image);
     window.draw(sprite);
     window.display();
     sf::Event event;
     while (true) {
          while (window.pollEvent(event)) {
               if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed) {
                    return;
               }
          }
     }
}
