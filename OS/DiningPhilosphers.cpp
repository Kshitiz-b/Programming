#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const int NUM_PHILOSOPHERS = 5; // Number of philosophers and forks

vector<mutex> forks(NUM_PHILOSOPHERS); // Mutexes for forks

void philosopher(int philosopherId) {
    int leftFork = philosopherId;
    int rightFork = (philosopherId + 1) % NUM_PHILOSOPHERS;

    // Pick up forks in a specific order to avoid deadlock
    lock(forks[leftFork], forks[rightFork]);

    // Eating
    cout << "Philosopher " << philosopherId << " is eating." << endl;
    // Simulating eating time
    this_thread::sleep_for(chrono::milliseconds(1000));

    // Put down forks
    forks[leftFork].unlock();
    forks[rightFork].unlock();

    // Thinking
    cout << "Philosopher " << philosopherId << " is thinking." << endl;
    // Simulating thinking time
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main() {
    vector<thread> philosophers;

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.emplace_back(philosopher, i);
    }

    // Join philosopher threads
    for (auto& thread : philosophers) {
        thread.join();
    }

    return 0;
}
