#include <cstdlib>
#include "glog/logging.h"
#include "RunningObservingSystem.h"

RunningObservingSystem* ptr = nullptr;

void close_running_observing_system_on_exit() {
  ptr->OnExit();
}

int main() {
  FLAGS_minloglevel = google::GLOG_INFO;
  FLAGS_logtostderr = false;
  FLAGS_alsologtostderr = true;
  google::InitGoogleLogging("02_observer");
  std::atexit(google::ShutdownGoogleLogging);
  std::atexit(close_running_observing_system_on_exit);
  
  RunningObservingSystem running_observing_system;
  ptr = &running_observing_system;
  running_observing_system.Do();
  
  return 0;
}
