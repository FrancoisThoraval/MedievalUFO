#ifndef scenery_hpp
#define scenery_hpp

#include "../Element/element.hpp"
#include <string>

class Scenery;
class Tree;
class Water;
class Hill;

/** Class principal du decors **/

class Scenery : public Element {
protected:
  std::string _name;
public:
  Scenery ();
  ~Scenery ();
  virtual std::string getName();
  void setName(std::string);
};


class Tree : public Scenery{
private:
  /* Vide */
public:
  Tree ();
  ~Tree ();

};

class Water : public Scenery {
private:
  /* Vide */
public:
  Water ();
  ~Water ();

};

class Hill : public Scenery {
private:
  /* Vide */
public:
  Hill ();
  ~Hill ();

};

#endif
