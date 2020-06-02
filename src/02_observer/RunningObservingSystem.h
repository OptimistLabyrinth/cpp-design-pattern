#ifndef CPP_DESIGN_PATTERN_RUNNING_OBSERVING_SYSTEM_H
#define CPP_DESIGN_PATTERN_RUNNING_OBSERVING_SYSTEM_H

#include <memory>
#include <thread>
#include "boost/asio.hpp"
#include "boost/system/error_code.hpp"
#include "Observable/ConcreteObservable.h"
#include "Observer/ConcreteObserver.h"

class RunningObservingSystem {
public:
  RunningObservingSystem();
  ~RunningObservingSystem();
  
  void Do();
  void OnExit();

private:
  void HandlerKeepIoContextAlive(const boost::system::error_code& ec);
  void SimpleTest();
  
  boost::asio::io_context io_context_;
  const unsigned long timer_duration_;
  std::unique_ptr<boost::asio::steady_timer> timer_to_keep_io_context_alive_;

  observer_pattern::ConcreteObservable concrete_observable_;
  std::thread concrete_observable_worker_;
  observer_pattern::ConcreteObserver concrete_observer_;
};

#endif //CPP_DESIGN_PATTERN_RUNNING_OBSERVING_SYSTEM_H
