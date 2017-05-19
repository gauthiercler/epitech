#include "Thread.hpp"

plazza::Thread::Thread() noexcept {

}

plazza::Thread::~Thread() {
}

std::thread::id plazza::Thread::getId() {
    return this->_thread.get_id();
}

bool plazza::Thread::joinable() {
  return this->_thread.joinable();
}

void plazza::Thread::join() {
  return this->_thread.join();
}

void plazza::Thread::detach() {
  return this->_thread.detach();
}

void plazza::Thread::swap(Thread &other) {
  return this->_thread.swap(other._thread);
}

std::thread::native_handle_type plazza::Thread::native_handle() {
  return this->_thread.native_handle();
}

plazza::Thread &plazza::Thread::operator=(plazza::Thread &&rhs) {
  this->_thread.operator=(std::move(rhs._thread));
  return *this;
}

plazza::Thread::Thread(plazza::Thread &&x) noexcept {
  this->_thread = std::thread(std::move(x.get()));
}

std::thread &plazza::Thread::get() {
  return this->_thread;
}

