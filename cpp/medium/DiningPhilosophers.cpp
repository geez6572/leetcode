#include <functional>
#include <mutex>
using namespace std;

class DiningPhilosophers {
private:
  mutex forks[5];
  mutex mtx;

public:
  DiningPhilosophers() {}

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int l = philosopher;
    int r = (philosopher + 1) % 5;
    mtx.lock();
    forks[l].lock();
    forks[r].lock();
    mtx.unlock();

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();

    forks[l].unlock();
    forks[r].unlock();
  }
};
