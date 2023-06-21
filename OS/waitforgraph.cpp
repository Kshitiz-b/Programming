#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

// Number of philosophers (and forks)
const int NUM_PHILOSOPHERS = 5;

// Mutexes for forks
vector<mutex> forks(NUM_PHILOSOPHERS);

// Function to simulate philosopher's behavior
void philosopher(int philosopherId)
{
    // Index of the left and right forks
    int leftFork = philosopherId;
    int rightFork = (philosopherId + 1) % NUM_PHILOSOPHERS;

    while (true)
    {
        // Thinking
        cout << "Philosopher " << philosopherId << " is thinking." << endl;

        // Request left fork
        forks[leftFork].lock();
        cout << "Philosopher " << philosopherId << " picks up the left fork." << endl;

        // Request right fork
        forks[rightFork].lock();
        cout << "Philosopher " << philosopherId << " picks up the right fork." << endl;

        // Eating
        cout << "Philosopher " << philosopherId << " is eating." << endl;

        // Release forks
        forks[rightFork].unlock();
        cout << "Philosopher " << philosopherId << " releases the right fork." << endl;
        forks[leftFork].unlock();
        cout << "Philosopher " << philosopherId << " releases the left fork." << endl;
    }
}

bool detectDeadlockUtil(int v, vector<bool> &visited, vector<bool> &inStack,
                        vector<vector<int>> &waitGraph, vector<vector<int>> &resourceGraph)
{
    visited[v] = true;
    inStack[v] = true;

    // Check for deadlock cycle in the wait-for graph
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        if (waitGraph[v][i] > 0)
        {
            if (!visited[i])
            {
                if (detectDeadlockUtil(i, visited, inStack, waitGraph, resourceGraph))
                    return true;
            }
            else if (inStack[i])
            {
                // Deadlock cycle found
                return true;
            }
        }
    }

    inStack[v] = false;

    // Check for deadlock cycle in the resource graph
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        if (resourceGraph[v][i] > 0)
        {
            if (!visited[i])
            {
                if (detectDeadlockUtil(i, visited, inStack, waitGraph, resourceGraph))
                    return true;
            }
            else if (inStack[i])
            {
                // Deadlock cycle found
                return true;
            }
        }
    }

    return false;
}

// Function to detect deadlock using wait-for graph and resource graph
bool detectDeadlock()
{
    vector<bool> visited(NUM_PHILOSOPHERS, false);
    vector<bool> inStack(NUM_PHILOSOPHERS, false);

    // Wait-for graph representation
    vector<vector<int>> waitGraph(NUM_PHILOSOPHERS, vector<int>(NUM_PHILOSOPHERS, 0));

    // Resource graph representation
    vector<vector<int>> resourceGraph(NUM_PHILOSOPHERS, vector<int>(NUM_PHILOSOPHERS, 0));

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        // Check if philosopher i is already visited
        if (!visited[i])
        {
            // Perform a depth-first search from philosopher i
            if (detectDeadlockUtil(i, visited, inStack, waitGraph, resourceGraph))
                return true;
        }
    }

    return false;
}

int main()
{
    // Create threads for philosophers
    vector<thread> threads;
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        threads.push_back(thread(philosopher, i));
    }

    // Wait for threads to finish
    for (auto &thread : threads)
    {
        thread.join();
    }

    // Detect deadlock
    if (detectDeadlock())
        cout << "Deadlock detected." << endl;
    else
        cout << "No deadlock detected." << endl;

    return 0;
}
