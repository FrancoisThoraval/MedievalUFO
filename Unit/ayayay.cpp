#include <iostream>
#include <typeinfo>
#include "unit.hpp"



template<class T>
class AYAYAY_Assistant {
private:
  std::string _advice;
  T _type;
public:
 AYAYAY_Assistant ();
 AYAYAY_Assistant(T type);
 ~AYAYAY_Assistant ();
 void setAdvice(std::string);
 void test();
 std::string getAdvice()const;


};


/*** CLASS AYAYAY ASSISTANT ***/

template<class T>
AYAYAY_Assistant<T>::AYAYAY_Assistant(){

}

template<class T>
AYAYAY_Assistant<T>::AYAYAY_Assistant(T type){
  this->_type = type;
}

template<class T>
AYAYAY_Assistant<T>::~AYAYAY_Assistant(){

}

template<class T>
void AYAYAY_Assistant<T>::test(){
  Unit u;
  PowerRanger pr;
  Putties pu;
  Zedd ze;
  RobotPR rp;
  TurtleTank tt;
  if(typeid(u)==typeid(this->_type)){
                                                //SI C'EST UNE UNITER
  } else if(typeid(pr)==typeid(this->_type)){
                                                //SI C'EST UN POWERRANGER
  } else if (typeid(pu)==typeid(this->_type)){
                                                //SI C'EST UN PUTTIES
  } else if(typeid(ze)==typeid(this->_type)){
                                                //SI C'EST UN ZEDD
  } else if(typeid(rp)==typeid(this->_type)){
                                                //SI C'EST UN ROBOTPR
  } else if(typeid(tt)==typeid(this->_type)){
                                                //SI C'EST UN TURTLETANK
  }
}
template<class T>
void AYAYAY_Assistant<T>::setAdvice(std::string advice){
  this->_advice = advice;
}
template<class T>
std::string AYAYAY_Assistant<T>::getAdvice()const{
  return(this->_advice);
}

/******************************************************/
