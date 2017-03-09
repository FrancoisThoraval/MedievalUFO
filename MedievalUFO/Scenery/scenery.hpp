#ifndef scenery_hpp
#define scenery_hpp

#include "../Element/element.hpp"

class Scenery;
class Tree;
class Water;
class Hill;

/** Class principal du decors **/

class Scenery : public Element {
private:
  string _name;
public:
  Scenery ();
  ~Scenery ();
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
