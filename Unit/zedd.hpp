#ifndef zedd_hpp
#define zedd_hpp
#include "unit.hpp"
#include "../Player/player.hpp"
#include "../Element/map.hpp"
#include <iostream>



// Element -> Unit  -> Map
//                  -> Zedd   -> Map
//                            -> Unit
// class Zedd;

class Zedd : public Unit{
private:
  bool _activeExpendNade;
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;
  Weapon* _thirdWeapon;
  Weapon* _fourthWeapon;

public:
  Zedd ();
  ~Zedd ();
  int getActiveExpendNade()const;
  int getInvocation()const;
  int getPuttiesCalling()const;
  int getApocalypseHole()const;

  void setActiceExpendNade(int);
  void setInvocation(int);
  void setPuttiesCalling(int);
  void setApocalypseHole(int);

  void ThrowExtendNade(Position,Map*,Player&);
  void EnableGrenade(Map);
  void Invocation(Position,Map*,Player&);
  void PuttiesCalling(Position,Map*,Player&);
  void ApocalypseHole(Map*,Player&);
};

#endif
