#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a segment
struct Segment {
    int segmentId;
    bool isOccupied;
    // Other relevant attributes
};

// Function to allocate a segment using the best fit strategy
int bestFit(vector<Segment>& segments, int logicalSegmentSize) {
    int bestFitIndex = -1;
    int minWastedSpace = INT_MAX;

    for (int i = 0; i < segments.size(); i++) {
        if (!segments[i].isOccupied) {
            int wastedSpace = segments[i].segmentId - logicalSegmentSize;
            if (wastedSpace >= 0 && wastedSpace < minWastedSpace) {
                minWastedSpace = wastedSpace;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        segments[bestFitIndex].isOccupied = true;
    }

    return bestFitIndex;
}

// Function to allocate a segment using the worst fit strategy
int worstFit(vector<Segment>& segments, int logicalSegmentSize) {
    int worstFitIndex = -1;
    int maxWastedSpace = INT_MIN;

    for (int i = 0; i < segments.size(); i++) {
        if (!segments[i].isOccupied) {
            int wastedSpace = segments[i].segmentId - logicalSegmentSize;
            if (wastedSpace >= 0 && wastedSpace > maxWastedSpace) {
                maxWastedSpace = wastedSpace;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        segments[worstFitIndex].isOccupied = true;
    }

    return worstFitIndex;
}

// Function to allocate a segment using the first fit strategy
int firstFit(vector<Segment>& segments, int logicalSegmentSize) {
    for (int i = 0; i < segments.size(); i++) {
        if (!segments[i].isOccupied && segments[i].segmentId >= logicalSegmentSize) {
            segments[i].isOccupied = true;
            return i;
        }
    }
    return -1;
}

int main() {
    // Example usage
    vector<Segment> segments = {
        {0, false},
        {1, true},
        {2, false},
        {3, false},
        {4, true},
        {5, false}
    };

    int logicalSegmentSize = 2;

    int firstFitIndex = firstFit(segments, logicalSegmentSize);
    if (firstFitIndex != -1) {
        cout << "First Fit: Allocated logical segment to segment " << firstFitIndex << endl;
    } else {
        cout << "First Fit: Unable to allocate logical segment" << endl;
    }

    int bestFitIndex = bestFit(segments, logicalSegmentSize);
    if (bestFitIndex != -1) {
        cout << "Best Fit: Allocated logical segment to segment " << bestFitIndex << endl;
    } else {
        cout << "Best Fit: Unable to allocate logical segment" << endl;
    }

    int worstFitIndex = worstFit(segments, logicalSegmentSize);
    if (worstFitIndex != -1) {
        cout << "Worst Fit: Allocated logical segment to segment " << worstFitIndex << endl;
    } else {
        cout << "Worst Fit: Unable to allocate logical segment" << endl;
    }


    return 0;
}
