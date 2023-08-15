/* A patient needs rehabilitation within the next N days (numbered from 0 to N-1). The rehabilitation consists of X sessions. For every rehabilitation session, other than the last one, the next session is exactly Y days later.
You are given an array A of N integers listing the costs of the individual rehabilitation sessions on the N days: that is rehabilitation on the K-th day costs A[K].
Write a function:
int solution (vector<int> &A, int X, int Y) ;
that, given the array A and the two integers X and Y, returns the minimum cost of rehabilitation.
It is guaranteed that it is always possible to complete all X rehabilitation sessions. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A, int X, int Y) {
    int N = A.size();
    vector<int> B;
    vector<int> C;
    int minCost=0;
    int j=0;
    for(int i=0;i<N;)
    {
        B.push_back(A[i]);
        if(i+Y < N)
        {
            i = i+Y;
        }
        else
        {
            break;
        }
    }
    int m = B.size();
    
    int min;
    int index;
    for (int i=0;i<X;i++)
    {
        min = *min_element(B.begin(), B.end());
        C.push_back(min);
        for(int i=0;i<m;i++)
        {
            if(B[i] == min)
            {
                index = i;
                break;
            }
        }
        B.erase(B.begin() + index);
        
        
    }
    
    int a = C.size();
    for(int i=0;i<a;i++)
    {
        minCost += C[i];
    }
    
    return minCost;
}

int main() {
    vector<int> A1 = {4, 2, 3, 7};
    int X1 = 2, Y1 = 2;
    cout << "Minimum cost: " << solution(A1, X1, Y1) << endl;

    vector<int> A2 = {10, 3, 4, 7};
    int X2 = 2, Y2 = 3;
    cout << "Minimum cost: " << solution(A2, X2, Y2) << endl;

    vector<int> A3 = {4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
    int X3 = 3, Y3 = 2;
    cout << "Minimum cost: " << solution(A3, X3, Y3) << endl;

    return 0;
}
