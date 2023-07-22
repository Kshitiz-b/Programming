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
        vector<bool> isAvailable(numResources, true);
        vector<bool> isAllocated(numProcesses, false);
        for (int count = 0; count < numProcesses; ++count)
        {
            bool found = false;
            for (int i = 0; i < numProcesses; ++i)
            {
                if (!visited[i] && isLessThanOrEqual(request[i], isAvailable))
                {
                    isAvailable = logicalOr(isAvailable, allocation[i]);
                    visited[i] = true;
                    safeSequence[count] = i;
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }
        bool deadlockDetected = false;
        for (int i = 0; i < numProcesses; ++i)
        {
            if (!visited[i])
            {
                deadlockDetected = true;
                cout << "Deadlock detected! Process " << i << " is involved." << endl;
            }
        }
        if (!deadlockDetected)
        {
            cout << "No deadlock detected." << endl;
            cout << "Safe sequence: ";
            for (int i = 0; i < numProcesses; ++i)
            {
                cout << safeSequence[i] << " ";
            }
            cout << endl;
        }
    }

private:
    bool isLessThanOrEqual(const vector<int> &a, const vector<bool> &b)
    {
        for (int i = 0; i < numResources; ++i)
        {
            if (a[i] > b[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> logicalOr(const vector<bool> &a, const vector<int> &b)
    {
        vector<bool> result(numResources, false);
        for (int i = 0; i < numResources; ++i)
        {
            result[i] = a[i] || (b[i] > 0);
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