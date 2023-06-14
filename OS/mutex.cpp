#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;
void criticalSection(int id)
{
    mtx.lock();
    cout << "Thread " << id << " Entered the critical section." << endl;
    cout << "Performing critical operations" << endl;
    cout << "Thread " << id << " Exiting the critical section." << endl;
    mtx.unlock();
}

int main()
{
    int numThreads = 5;
    thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i] = thread(criticalSection, i);
    }
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }
    return 0;
}