#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a page frame
struct PageFrame {
    int frameId;
    bool isOccupied;
    // Other relevant attributes
};

// Function to allocate a page frame using the best fit strategy
int bestFit(vector<PageFrame>& pageFrames, int processSize) {
    int bestFitIndex = -1;
    int minWastedSpace = INT_MAX;

    for (int i = 0; i < pageFrames.size(); i++) {
        if (!pageFrames[i].isOccupied) {
            int wastedSpace = pageFrames[i].frameId - processSize;
            if (wastedSpace >= 0 && wastedSpace < minWastedSpace) {
                minWastedSpace = wastedSpace;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        pageFrames[bestFitIndex].isOccupied = true;
    }

    return bestFitIndex;
}

// Function to allocate a page frame using the worst fit strategy
int worstFit(vector<PageFrame>& pageFrames, int processSize) {
    int worstFitIndex = -1;
    int maxWastedSpace = INT_MIN;

    for (int i = 0; i < pageFrames.size(); i++) {
        if (!pageFrames[i].isOccupied) {
            int wastedSpace = pageFrames[i].frameId - processSize;
            if (wastedSpace >= 0 && wastedSpace > maxWastedSpace) {
                maxWastedSpace = wastedSpace;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        pageFrames[worstFitIndex].isOccupied = true;
    }

    return worstFitIndex;
}

// Function to allocate a page frame using the first fit strategy
int firstFit(vector<PageFrame>& pageFrames, int processSize) {
    for (int i = 0; i < pageFrames.size(); i++) {
        if (!pageFrames[i].isOccupied && pageFrames[i].frameId >= processSize) {
            pageFrames[i].isOccupied = true;
            return i;
        }
    }
    return -1;
}

int main() {
    // Example usage
    vector<PageFrame> pageFrames = {
        {0, false},
        {1, false},
        {2, true},
        {3, false},
        {4, true},
        {5, false}
    };

    int processSize = 1;
    int firstFitIndex = firstFit(pageFrames, processSize);
    if (firstFitIndex != -1) {
        cout << "First Fit: Allocated process to page frame " << firstFitIndex << endl;
    } else {
        cout << "First Fit: Unable to allocate process" << endl;
    }

    int bestFitIndex = bestFit(pageFrames, processSize);
    if (bestFitIndex != -1) {
        cout << "Best Fit: Allocated process to page frame " << bestFitIndex << endl;
    } else {
        cout << "Best Fit: Unable to allocate process" << endl;
    }

    int worstFitIndex = worstFit(pageFrames, processSize);
    if (worstFitIndex != -1) {
        cout << "Worst Fit: Allocated process to page frame " << worstFitIndex << endl;
    } else {
        cout << "Worst Fit: Unable to allocate process" << endl;
    }


    return 0;
}
