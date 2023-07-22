#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DeadlockDetection
{
private:
    int numProcesses;
    int numResources;
    vector<vector<int>> allocation;
    vector<vector<int>> request;
    vector<bool> visited;
    vector<bool> safeSequence;

public:
    DeadlockDetection(int nProcesses, int nResources) : numProcesses(nProcesses), numResources(nResources),
                                                        allocation(nProcesses, vector<int>(nResources)),
                                                        request(nProcesses, vector<int>(nResources)),
                                                        visited(nProcesses, false),
                                                        safeSequence(nProcesses, false) {}
    void setAllocationMatrix(const vector<vector<int>> &allocationMatrix)
    {
        allocation = allocationMatrix;
    }
    void setRequestMatrix(const vector<vector<int>> &requestMatrix)
    {
        request = requestMatrix;
    }
    void detectDeadlock()
    {
        vector<int> available = calculateAvailable();
        vector<vector<int>> need = calculateNeed();
        vector<int> work = available;
        queue<int> safeQueue;
        for (int i = 0; i < numProcesses; ++i)
        {
            if (!visited[i] && isLessThanOrEqual(need[i], work))
            {
                safeQueue.push(i);
                visited[i] = true;
                work = add(work, allocation[i]);
                i = -1;
            }
        }
        while (!safeQueue.empty())
        {
            int process = safeQueue.front();
            safeQueue.pop();
            safeSequence[process] = true;
        }
        cout << "Safe sequence: ";
        for (int i = 0; i < numProcesses; ++i)
        {
            if (safeSequence[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
        bool deadlockDetected = false;
        for (int i = 0; i < numProcesses; ++i)
        {
            if (!visited[i])
            {
                cout << "Deadlock detected! Process " << i << " is involved." << endl;
                deadlockDetected = true;
            }
        }
        if (!deadlockDetected)
        {
            cout << "No deadlock detected." << endl;
        }
    }

private:
    vector<int> calculateAvailable()
    {
        vector<int> available(numResources, 0);
        for (int j = 0; j < numResources; ++j)
        {
            for (int i = 0; i < numProcesses; ++i)
            {
                available[j] += allocation[i][j];
            }
        }
        return available;
    }
    vector<vector<int>> calculateNeed()
    {
        vector<vector<int>> need(numProcesses, vector<int>(numResources));
        for (int i = 0; i < numProcesses; ++i)
        {
            for (int j = 0; j < numResources; ++j)
            {
                need[i][j] = request[i][j] - allocation[i][j];
            }
        }
        return need;
    }
    bool isLessThanOrEqual(const vector<int> &a, const vector<int> &b)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] > b[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> add(const vector<int> &a, const vector<int> &b)
    {
        vector<int> result(a.size());
        for (int i = 0; i < a.size(); ++i)
        {
            result[i] = a[i] + b[i];
        }
        return result;
    }
};

int main()
{
    DeadlockDetection dd(5, 3);
    vector<vector<int>> allocationMatrix = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};
    vector<vector<int>> requestMatrix = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}};
    dd.setAllocationMatrix(allocationMatrix);
    dd.setRequestMatrix(requestMatrix);
    dd.detectDeadlock();
    return 0;
}
