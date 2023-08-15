/* You are given an undirected graph consisting of N vertices, numbered from 0 to N-1, connected with M edges. The graph is described by two arrays, A and B, both of length M. A pair (A[K], B[K]), for K from 0 to M-1, describes an edge between vertex A|K] and vertex B|K].
Each second, every vertex with at most one edge connected to it disappears. Every edge which is connected to one of the disappearing vertices also disappears.
After how many seconds will the vertices stop disappearing?
Consider a graph with N = 7 vertices and following 6 edges: (0, 1), (1, 2), (2, 0), (1, 4), (4, 5) and (4, 6).
After the first second, vertices 3, 5, and 6 (marked red in the picture above) will disappear:
After the next second vertex 4 will disappear and only vertices 0, 1 and 2 will be left:
All three remaining vertices are connected to two edges, so none of will ever disappear and the answer is 2.
Write a function:
int solution (int N, vector<int> &A, vector<int> &B) ;
that, given an integer N and two arrays A and B of M integers each, returns the number of seconds after which the vertices will stop disappearing, or 0 if no vertices will ever disappear. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <bitset>
#include <limits>

using namespace std;

int solution(int N, vector<int> &A, vector<int> &B) {
    
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); ++i) {
        ++m[A[i]];
        ++m[B[i]];
    }
    
    int seconds = 0;
    int count = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second <= 1) {
            ++count;
        }
    }
    
    return count;
}

int main() {
    int N = 7;
    vector<int> A = {0, 1, 2, 1, 4, 4};
    vector<int> B = {1, 2, 0, 4, 5, 6};

    int result = solution(N, A, B);
    cout << "Number of seconds: " << result << endl;

    return 0;
}