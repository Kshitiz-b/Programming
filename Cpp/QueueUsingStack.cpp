#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> st1, st2;

void reverseStack()
{
    while (!st1.empty())
    {
        int temp = st1.top();
        st1.pop();
        st2.push(temp);
    }
}

void Enqueue(int x)
{
    st1.push(x);
}

void Dequeue()
{
    reverseStack();
    st2.pop();
}

void Front()
{
    reverseStack();
    cout << st2.top() << endl;
}

int main()
{
    int n;

    do
    {
        cin >> n;

        switch (n)
        {
        case 0:
            break;
        case 1:
            int x;
            cin >> x;
            Enqueue(x);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Front();
            break;
        default:
            cout << "Please enter a valid expression\n";
            break;
        }
    } while (n != 0);

    return 0;
}