#include "Observable.h"

namespace observer_pattern {

Observable::Observable()
    : loop_continue_(true)
{
}

Observable::~Observable() = default;

void Observable::RegisterObserver(Observer& observer) {
  observers_.insert(&observer);
}

void Observable::UnregisterObserver(Observer& observer) { 
  observers_.erase(&observer);
}

void Observable::Notify() {
  for (auto observer : observers_) {
    observer->Update();
  }
}

void Observable::OnExitObservable() {
  loop_continue_ = false;
  for (auto observer : observers_) {
    UnregisterObserver(*observer);
  }
}

}
