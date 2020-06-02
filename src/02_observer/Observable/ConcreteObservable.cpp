#include "ConcreteObservable.h"
#include <random>
#include <unistd.h>

namespace observer_pattern {

ConcreteObservable::ConcreteObservable()
    : data_(0)
{
}

ConcreteObservable::~ConcreteObservable() = default;

void ConcreteObservable::Work() {
  std::random_device rd;
  std::mt19937_64 mt(rd());
  std::uniform_int_distribution<std::mt19937_64::result_type> dist5(1,5);
  
  while (loop_continue_) {
    data_ += dist5(mt);
    if ((data_ % 5) == 0) {
      Notify();
    }
    sleep(1);
  }
}

int ConcreteObservable::getData() {
  return data_;
}

}
