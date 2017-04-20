#include <iostream>
#include <typeinfo>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "unit.hpp"

/*******************************************************/
template<typename T>
void Advice_ayayay(sf::RenderWindow& _window,T type){                                                            // fonction qui suivant le type de l'unité en parametre va afficher cest point de vie et d'attaque
  // sf::Texture t;
  // int x;
  // int y;
  // t.loadFromFile("./Textures/LPC_Terrain/terrain.png");
  // sf::Sprite s;
   sf::Text text;
   sf::Font font;
   text.setFont(font);
   font.loadFromFile("./arial.ttf");
   text.setColor(sf::Color::White);
   text.setCharacterSize(15);
  // s.setTexture(t);
  // s.setTextureRect(sf::IntRect());
  // s.setPosition(x*50,y*50);
  // _window.draw(s);

  if(type->getName()=="Zedd"){
    //std::cout << "TEST AYAYAYAYY" << std::endl;
    text.setString("HP : "+std::to_string(type->getHealthPoints()));
    text.setPosition(340,500);
    _window.draw(text);
    text.setString("PM : "+std::to_string(type->getMovement()));
    text.setPosition(340,530);
    _window.draw(text);
    _window.display();

  } else if(type->getName()=="Putties"){

    //std::cout << "TEST AYAYAYAYY" << std::endl;
    text.setString("HP :"+std::to_string(type->getHealthPoints()));
    text.setPosition(340,500);
    _window.draw(text);
    text.setString("PM : "+std::to_string(type->getMovement()));
    text.setPosition(340,530);
    _window.draw(text);
    _window.display();
    // text.setString("C'est un Putties, il lui reste : "+pu.getHealthPoints());
  }  else if (type->getName()=="RobotPR"){
    //std::cout << "TEST AYAYAYAYY" << std::endl;
    text.setString("HP :"+std::to_string(type->getHealthPoints()));
    text.setPosition(340,500);
    _window.draw(text);
    text.setString("PM : "+std::to_string(type->getMovement()));
    text.setPosition(340,530);
    _window.draw(text);
    _window.display();
    // RobotPR rpr;
    // rpr = type;
    // text.setString("C'est LE RobotPR, il lui reste : "+std::to_string(rpr.getHealthPoints()));
  } else if(type->getName()=="TurtleTank"){
    //std::cout << "TEST AYAYAYAYY" << std::endl;
    text.setString("HP :"+std::to_string(type->getHealthPoints()));
    text.setPosition(340,500);
    _window.draw(text);
    text.setString("PM : "+std::to_string(type->getMovement()));
    text.setPosition(340,530);
    _window.draw(text);
    _window.display();
    // TurtleTank tt;
    // tt = type;
    // text.setString("C'est le ROBOT TORTUE ULTIME !!, il lui reste : "+std::to_string(tt.getHealthPoints()));
  } else {
    //std::cout << "TEST AYAYAYAYY" << std::endl;
    text.setString("HP :"+std::to_string(type->getHealthPoints()));
    text.setPosition(340,500);
    _window.draw(text);
    text.setString("PM : "+std::to_string(type->getMovement()));
    text.setPosition(340,530);
    _window.draw(text);
    _window.display();
    // PowerRanger pr;
    // pr = type;
    // text.setString("C'est un des PowerRanger ! il lui reste "++std::to_string(pr.getHealthPoints()));
    // std::cout<<"GROSSE BITE"<<std::endl;
    // std::string test = "Il lui reste "+std::to_string(type->getHealthPoints());
    // std::cout<<test<<std::endl<<"FIN"<<std::endl;;
  }
  // text.setPosition();
  // _window.draw(text);
  // */

}
/******************************************************/
