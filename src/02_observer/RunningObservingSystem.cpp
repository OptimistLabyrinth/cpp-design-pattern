#include "RunningObservingSystem.h"

#include <functional>
#include "boost/bind.hpp"
#include "glog/logging.h"

RunningObservingSystem::RunningObservingSystem()
    : io_context_()
    , timer_duration_(100)
    , timer_to_keep_io_context_alive_()
    , concrete_observable_()
    , concrete_observer_(concrete_observable_)
{
}

RunningObservingSystem::~RunningObservingSystem() { 
  OnExit();
}

void RunningObservingSystem::Do() {
  concrete_observable_.RegisterObserver(concrete_observer_);
  concrete_observable_worker_ = std::move(std::thread(
      &observer_pattern::ConcreteObservable::Work, &concrete_observable_));

  timer_to_keep_io_context_alive_ = std::make_unique<boost::asio::steady_timer>(
      io_context_, boost::asio::chrono::seconds(timer_duration_));
  timer_to_keep_io_context_alive_->async_wait(boost::bind(
          &RunningObservingSystem::HandlerKeepIoContextAlive,this, boost::asio::placeholders::error));
  io_context_.run();
}

void RunningObservingSystem::OnExit() {
  concrete_observable_.OnExitObservable();
  if (concrete_observable_worker_.joinable()) {
    concrete_observable_worker_.join();
  }
  if (timer_to_keep_io_context_alive_) {
    timer_to_keep_io_context_alive_->cancel();
    timer_to_keep_io_context_alive_.reset();
  }
  if (! io_context_.stopped()) {
    io_context_.stop();
  }
}

void RunningObservingSystem::HandlerKeepIoContextAlive(const boost::system::error_code &ec) {
  if (! ec) {
    timer_to_keep_io_context_alive_ = std::make_unique<boost::asio::steady_timer>(
        io_context_, boost::asio::chrono::seconds(timer_duration_));
    timer_to_keep_io_context_alive_->async_wait(boost::bind(
        &RunningObservingSystem::HandlerKeepIoContextAlive, this, boost::asio::placeholders::error));
  } else {
  }
}

void RunningObservingSystem::SimpleTest() {
  if (timer_to_keep_io_context_alive_) {
    LOG(INFO) << "initially valid";
  } else {
    LOG(INFO) << "initially invalid";
  }

  timer_to_keep_io_context_alive_ = std::make_unique<boost::asio::steady_timer>(
      io_context_, boost::asio::chrono::seconds(timer_duration_));
  if (timer_to_keep_io_context_alive_) {
    LOG(INFO) << "valid unique_ptr";
  } else {
    LOG(INFO) << "invalid";
  }

  timer_to_keep_io_context_alive_.reset();
  if (timer_to_keep_io_context_alive_) {
    LOG(INFO) << "valid unique_ptr";
  } else {
    LOG(INFO) << "invalid";
  }
}
