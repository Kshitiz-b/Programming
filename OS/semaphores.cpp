#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
public:
    Semaphore(int count = 0) : count_(count) {}

    void notify() {
        unique_lock<mutex> lock(mutex_);
        ++count_;
        condition_.notify_one();
    }

    void wait() {
        unique_lock<mutex> lock(mutex_);
        condition_.wait(lock, [this]() { return count_ > 0; });
        --count_;
    }

private:
    mutex mutex_;
    condition_variable condition_;
    int count_;
};

Semaphore semaphore(1);  // Initialize the semaphore with a count of 1

void worker(int id) {
    cout << "Worker " << id << " is waiting." << endl;
    semaphore.wait();  // Wait for the semaphore

    cout << "Worker " << id << " starts working." << endl;
    this_thread::sleep_for(chrono::seconds(2));  // Simulate some work

    cout << "Worker " << id << " finishes working." << endl;
    semaphore.notify();  // Release the semaphore
}

int main() {
    thread workers[3];

    for (int i = 0; i < 3; ++i) {
        workers[i] = thread(worker, i + 1);
    }

    for (int i = 0; i < 3; ++i) {
        workers[i].join();
    }

    return 0;
}
