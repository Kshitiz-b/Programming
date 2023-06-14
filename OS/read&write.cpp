#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ReadWriteLock
{
public:
    ReadWriteLock() : readersCount(0), writersCount(0) {}

    void acquireReadLock()
    {
        unique_lock<mutex> lock(mutex_);
        condition_.wait(lock, [this]()
                        { return writersCount == 0; });
        ++readersCount;
    }

    void releaseReadLock()
    {
        unique_lock<mutex> lock(mutex_);
        --readersCount;
        if (readersCount == 0)
        {
            condition_.notify_all();
        }
    }

    void acquireWriteLock()
    {
        unique_lock<mutex> lock(mutex_);
        condition_.wait(lock, [this]()
                        { return readersCount == 0 && !writing; });
        writing = true;
        ++writersCount;
    }

    void releaseWriteLock()
    {
        unique_lock<mutex> lock(mutex_);
        writing = false;
        --writersCount;
        condition_.notify_all();
    }

private:
    mutex mutex_;
    condition_variable condition_;
    int readersCount;
    int writersCount;
    bool writing;
};

ReadWriteLock rwLock;

void reader(int id)
{
    cout << "Reader " << id << " is acquiring the read lock." << endl;
    rwLock.acquireReadLock();

    cout << "Reader " << id << " is reading." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Simulate reading

    cout << "Reader " << id << " is releasing the read lock." << endl;
    rwLock.releaseReadLock();
}

void writer(int id)
{
    cout << "Writer " << id << " is acquiring the write lock." << endl;
    rwLock.acquireWriteLock();

    cout << "Writer " << id << " is writing." << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Simulate writing

    cout << "Writer " << id << " is releasing the write lock." << endl;
    rwLock.releaseWriteLock();
}

int main()
{
    thread readers[3];
    thread writers[2];

    for (int i = 0; i < 3; ++i)
    {
        readers[i] = thread(reader, i + 1);
    }

    for (int i = 0; i < 2; ++i)
    {
        writers[i] = thread(writer, i + 1);
    }

    for (int i = 0; i < 3; ++i)
    {
        readers[i].join();
    }

    for (int i = 0; i < 2; ++i)
    {
        writers[i].join();
    }

    return 0;
}
