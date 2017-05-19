/*
** ThreadPool.cpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/ThreadPool.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Apr 15 17:25:59 2017 Gauthier Cler
** Last update Sat Apr 15 17:25:59 2017 Gauthier Cler
*/

#include <iostream>
#include <Worker.hpp>
#include <Error.hpp>
#include "ThreadPool.hpp"

plazza::ThreadPool::ThreadPool(std::function<void (const std::vector<std::string> &)> callBack) : _stop(false),_callback(callBack){

}

plazza::ThreadPool::~ThreadPool() {

}

void plazza::ThreadPool::addJob(const std::string &fileName, Information type) {
  {
    std::unique_lock<Mutex<std::mutex>>	lock(this->_queueLock);
    this->_jobsQueue.push({fileName, type});
  }
  this->_condition.notifyOne();
}

size_t plazza::ThreadPool::getNbWorkers() const {
  return this->_workers.size();
}

void plazza::ThreadPool::waitJob() {
  std::pair<std::string, Information>	job;
  while (true) {
    {
      job.first = std::string("");
      std::unique_lock<Mutex<std::mutex>> lock(this->_queueLock);
      this->_condition.wait(lock,
			    [this] { return this->_stop || !this->_jobsQueue.empty(); });
    if (!this->_jobsQueue.empty()) {
      job = this->_jobsQueue.front();
      this->_jobsQueue.pop();
    }else if (this->_stop)
      return ;
    }
    if (job.first.length() > 0) {
      this->setWorkerState(true);
      this->getWorker().performJob(job.first, job.second);
      this->setWorkerState(false);
      this->_callback(this->getWorker().getResults());
    }
  }
}

void plazza::ThreadPool::stop() {
  this->_stop = true;
  this->_condition.notifyAll();
  for (auto &thread : this->_workers)
    if (thread.getThread().joinable())
      thread.getThread().join();
}

size_t plazza::ThreadPool::getQueueLength() const {
  return static_cast<size_t>(this->_jobsQueue.size());
}

size_t plazza::ThreadPool::getNbFreeWorkers() const {
  size_t	sum  = 0;

  for (auto &worker : this->_workers)
    if (!worker.isBusy())
      sum += 1;

  return sum;
}

void plazza::ThreadPool::setWorkerState(bool state) {
  this->getWorker().setBusy(state);
}

void plazza::ThreadPool::createWorkers(size_t nbWorkers) {
  for (size_t i = 0; i < nbWorkers; i++)
    this->_workers.push_back(Worker());
  for (auto &worker : this->_workers)
    worker.start(std::bind(&ThreadPool::waitJob, this));
}

plazza::ThreadPool::ThreadPool(plazza::ThreadPool &&threadPool) :
_workers(std::move(threadPool._workers)),
_queueLock(std::move(threadPool._queueLock)),
_jobsQueue(std::move(threadPool._jobsQueue)),
_condition(std::move(threadPool._condition)),
_stop(std::move(threadPool._stop))
{

}

plazza::Worker &plazza::ThreadPool::getWorker() {
  auto worker = std::find_if(this->_workers.begin(), this->_workers.end(),
		      [](const Worker &worker){ return worker.getThread().getId() == std::this_thread::get_id(); });
  if (worker == this->_workers.end())
    throw plazza::Error("Worker not found");
  return *worker;
}
