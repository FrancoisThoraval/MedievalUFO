#ifndef carte_hpp
#define carte_hpp

#include "element.hpp"

class Map {
private:
  Element **_map;
  Element **_secondMap;

public:
  Map ();
  ~Map ();
  friend class Element;
  Element getElement(Position)const;
  void setElement(Position,Element);
};

#endif
