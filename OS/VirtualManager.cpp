#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class ResourceManager {
private:
    unordered_map<int, int> resourceMap;
    unordered_map<int, vector<int>> processMap;

public:
    ResourceManager() {}

    void allocateResource(int processID, int resourceID) {
        if (resourceMap[resourceID] > 0) {
            resourceMap[resourceID]--;
            processMap[processID].push_back(resourceID);
            cout << "Resource " << resourceID << " allocated to Process " << processID << endl;
        } else {
            cout << "Resource " << resourceID << " is currently unavailable. Process " << processID << " is waiting." << endl;
            bool isSafeState = checkSafeState();
            if (!isSafeState) {
                cout << "Deadlock detected. Unable to allocate resources." << endl;
                // Implement deadlock resolution logic here
            }
        }
    }

    void releaseResource(int processID, int resourceID) {
        resourceMap[resourceID]++;
        processMap[processID].erase(find(processMap[processID].begin(), processMap[processID].end(), resourceID));
        cout << "Resource " << resourceID << " released from Process " << processID << endl;
    }

    void printResourceStatus() {
        for (const auto& pair : resourceMap) {
            cout << "Resource " << pair.first << " has " << pair.second << " available" << endl;
        }
    }

    void printProcessResources(int processID) {
        cout << "Process " << processID << " has allocated resources: ";
        for (int resourceID : processMap[processID]) {
            cout << resourceID << " ";
        }
        cout << endl;
    }

    bool checkSafeState() {
        // Banker's algorithm for deadlock avoidance
        unordered_map<int, int> availableResources = resourceMap;
        unordered_map<int, vector<int>> allocatedResources = processMap;

        vector<bool> executed(processMap.size(), false);
        vector<int> safeSequence;

        int n = processMap.size();
        int m = resourceMap.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (executed[j] == false) {
                    bool isPossible = true;
                    for (int k = 0; k < m; ++k) {
                        if (availableResources[k] < allocatedResources[j][k]) {
                            isPossible = false;
                            break;
                        }
                    }

                    if (isPossible) {
                        executed[j] = true;
                        safeSequence.push_back(j);
                        for (int k = 0; k < m; ++k) {
                            availableResources[k] += allocatedResources[j][k];
                        }
                    }
                }
            }
        }

        return (safeSequence.size() == n);
    }
};

class ProcessManager {
private:
    int processIDCounter;
    queue<int> readyQueue;

public:
    ProcessManager() : processIDCounter(1) {}

    int createProcess() {
        int processID = processIDCounter++;
        cout << "Process " << processID << " created." << endl;
        return processID;
    }

    void scheduleProcess(int processID) {
        readyQueue.push(processID);
        cout << "Process " << processID << " scheduled for execution." << endl;
    }

    int getNextProcess() {
        if (readyQueue.empty()) {
            cout << "No processes in the ready queue." << endl;
            return -1;
        }

        int nextProcess = readyQueue.front();
        readyQueue.pop();
        cout << "Executing Process " << nextProcess << endl;
        return nextProcess;
    }
};

int main() {
    ResourceManager resourceManager;
    ProcessManager processManager;

    int p1 = processManager.createProcess();
    int p2 = processManager.createProcess();

    resourceManager.allocateResource(p1, 1);
    resourceManager.allocateResource(p2, 2);
    resourceManager.allocateResource(p1, 2);

    resourceManager.releaseResource(p1, 1);
    resourceManager.releaseResource(p2, 2);

    resourceManager.printResourceStatus();
    resourceManager.printProcessResources(p1);
    resourceManager.printProcessResources(p2);

    return 0;
}
