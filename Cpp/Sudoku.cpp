#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

bool notInRow(char arr[][9], int row)
{
    set<char> st; // set is a DS that ensures that stores unique values.

    for (int i = 0; i < 9; i++)
    {
        if (st.find(arr[row][i]) != st.end())
            return false;

        if (arr[row][i] != '.')
            st.insert(arr[row][i]);
    }
    return true;
}

bool notInCol(char arr[][9], int col)
{
    set<char> st;

    for (int i = 0; i < 9; i++)
    {
        if (st.find(arr[i][col]) != st.end())
            return false;

        if (arr[i][col] != '.')
            st.insert(arr[i][col]);
    }
    return true;
}

bool notInBox(char arr[][9], int start_row, int start_col)
{
    set<char> st;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            char curr = arr[start_row + row][start_col + col];

            if (st.find(curr) != st.end())
                return false;

            if (curr != '.')
                st.insert(curr);
        }
    }
    return true;
}

bool isValid(char arr[][9], int row, int col)
{
    return notInRow(arr, row) && notInCol(arr, col) && notInBox(arr, row - row % 3, col - col % 3);
}

bool checkSudoku(int n, char A[][9])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (!isValid(A, i, j))
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    char A[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << (checkSudoku(9, A) ? "YES\n" : "NO\n");

    return 0;
}