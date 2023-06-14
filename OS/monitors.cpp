#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Monitor {
private:
    mutex mtx;
    condition_variable cv;
    bool flag;

public:
    Monitor() : flag(false) {}

    void wait() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return flag; });
        flag = false;
    }

    void notify() {
        unique_lock<mutex> lock(mtx);
        flag = true;
        cv.notify_one();
    }
};

Monitor monitor;

void worker(int id) {
    cout << "Worker " << id << " is waiting." << endl;
    monitor.wait();

    cout << "Worker " << id << " starts working." << endl;
    this_thread::sleep_for(chrono::seconds(2));  // Simulate some work

    cout << "Worker " << id << " finishes working." << endl;
}

int main() {
    thread workers[3];

    for (int i = 0; i < 3; ++i) {
        workers[i] = thread(worker, i + 1);
    }

    // Wait for a while before notifying the workers
    this_thread::sleep_for(chrono::seconds(3));

    cout << "Notifying the workers..." << endl;
    monitor.notify();

    for (int i = 0; i < 3; ++i) {
        workers[i].join();
    }

    return 0;
}
