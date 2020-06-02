#include "ConcreteObserver.h"
#include "glog/logging.h"

namespace observer_pattern {

ConcreteObserver::ConcreteObserver(ConcreteObservable& concrete_observable)
    : concrete_observable_(concrete_observable)
{
}

ConcreteObserver::~ConcreteObserver() noexcept = default;

void ConcreteObserver::Update() {
  PrintData();
}

void ConcreteObserver::PrintData() {
  LOG(INFO) << concrete_observable_.getData();
}

}
