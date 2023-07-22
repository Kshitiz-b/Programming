#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

class DiningPhilosophers
{
private:
    int numPhilosophers;
    vector<thread> philosophers;
    vector<mutex> forks;
    vector<int> eatCount;
    mutex printMutex;
    const int MAX_EAT_CYCLES = 3;

public:
    DiningPhilosophers(int num) : numPhilosophers(num), forks(num), eatCount(num, 0) {}

    void startEating()
    {
        for (int i = 0; i < numPhilosophers; ++i)
        {
            philosophers.emplace_back(&DiningPhilosophers::dine, this, i);
        }
        for (int i = 0; i < numPhilosophers; ++i)
        {
            philosophers[i].join();
        }
    }

private:
    void dine(int philosopherID)
    {
        int leftFork = philosopherID;
        int rightFork = (philosopherID + 1) % numPhilosophers;
        while (eatCount[philosopherID] < MAX_EAT_CYCLES)
        {
            {
                unique_lock<mutex> leftLock(forks[leftFork]);
                unique_lock<mutex> rightLock(forks[rightFork]);
                printMutex.lock();
                cout << "Philosopher " << philosopherID << " is eating." << endl;
                printMutex.unlock();
                this_thread::sleep_for(chrono::seconds(2));
                printMutex.lock();
                cout << "Philosopher " << philosopherID << " has finished eating." << endl;
                printMutex.unlock();
            }
            this_thread::sleep_for(chrono::seconds(2));
            printMutex.lock();
            cout << "Philosopher " << philosopherID << " is thinking." << endl;
            printMutex.unlock();
            ++eatCount[philosopherID];
        }
    }
};

int main()
{
    int numPhilosophers = 5;
    DiningPhilosophers dp(numPhilosophers);
    dp.startEating();
    return 0;
}
