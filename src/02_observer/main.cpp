#include <csignal>
#include <cstdlib>
#include "glog/logging.h"
#include "RunningObservingSystem.h"

RunningObservingSystem* ptr = nullptr;

void close_running_observing_system_on_exit(int signo) {
  if (ptr != nullptr) {
    ptr->OnExit();
  }
}

int main() {
  FLAGS_minloglevel = google::GLOG_INFO;
  FLAGS_logtostderr = false;
  FLAGS_alsologtostderr = true;
  google::InitGoogleLogging("02_observer");
  std::atexit(google::ShutdownGoogleLogging);

  std::signal(SIGINT, close_running_observing_system_on_exit);
  std::signal(SIGTERM, close_running_observing_system_on_exit);
#ifdef SIGQUIT
  std::signal(SIGQUIT, close_running_observing_system_on_exit);
#endif
  
  RunningObservingSystem running_observing_system;
  ptr = &running_observing_system;
  running_observing_system.Do();
  ptr = nullptr;
  
  return 0;
}
