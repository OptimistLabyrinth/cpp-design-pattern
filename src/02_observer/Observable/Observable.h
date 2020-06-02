#ifndef CPP_DESIGN_PATTERN_OBSERVABLE_H
#define CPP_DESIGN_PATTERN_OBSERVABLE_H

#include <atomic>
#include <set>
#include "../Observer/Observer.h"

namespace observer_pattern {

class Observable {
public:
  Observable();
  virtual ~Observable();

  void RegisterObserver(Observer& observer);
  void UnregisterObserver(Observer& observer);
  void Notify();
  void OnExitObservable();

protected:
  std::set<Observer*> observers_;
  std::atomic_bool loop_continue_;
};

}

#endif //CPP_DESIGN_PATTERN_OBSERVABLE_H
