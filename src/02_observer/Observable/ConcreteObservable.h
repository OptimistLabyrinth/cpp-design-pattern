#ifndef CPP_DESIGN_PATTERN_CONCRETE_OBSERVABLE_H
#define CPP_DESIGN_PATTERN_CONCRETE_OBSERVABLE_H

#include "Observable.h"

namespace observer_pattern {

class ConcreteObservable : public Observable {
public:
  ConcreteObservable();
  ~ConcreteObservable() override;
  
  void Work();
  int getData();

private:
  unsigned long data_;
};

}

#endif //CPP_DESIGN_PATTERN_CONCRETE_OBSERVABLE_H
