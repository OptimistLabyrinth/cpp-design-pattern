#ifndef CPP_DESIGN_PATTERN_CONCRETE_OBSERVER_H
#define CPP_DESIGN_PATTERN_CONCRETE_OBSERVER_H

#include "Observer.h"
#include "../Observable/ConcreteObservable.h"

namespace observer_pattern {

class ConcreteObserver : public Observer {
public:
  explicit ConcreteObserver(ConcreteObservable& concrete_observable);
  ~ConcreteObserver() override;

  void Update() override;
  void PrintData();

private:
  ConcreteObservable& concrete_observable_;
};

}

#endif //CPP_DESIGN_PATTERN_CONCRETE_OBSERVER_H
