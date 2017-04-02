#ifndef ayayay_hpp
#define ayayay_hpp

#include "unit.hpp"

class AYAYAY_Assistant {
private:
  std::string _advice;
public:
 AYAYAY_Assistant ();
 ~AYAYAY_Assistant ();
 void setAdvice(std::string);
 std::string getAdvice()const;


};

#endif
