#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CustomStack
{
private:
    string text;
    stack<pair<int, string>> operations;

public:
    void insert(const string &value)
    {
        text.insert(text.begin(), value.begin(), value.end());
        operations.push(make_pair(1, value));
    }

    void deleteChars(int value)
    {
        string deletedChars = text.substr(0, value);
        text.erase(0, value);
        operations.push(make_pair(2, deletedChars));
    }

    char get(int value)
    {
        return text[value - 1];
    }

    void undo()
    {
        if (!operations.empty())
        {
            operation = operations.top();
            operations.pop();
            if (operation.first == 1)
            {
                text.erase(0, operation.second.length());
            }
            else if (operation.first == 2)
            {
                text = operation.second + text;
            }
        }
    }
};

int main()
{
    CustomStack customStack;
    string input;

    while (cin >> input)
    {
        if (input[0] == '1')
        {
            string value;
            cin >> value;
            customStack.insert(value);
        }
        else if (input[0] == '2')
        {
            int value;
            cin >> value;
            customStack.deleteChars(value);
        }
        else if (input[0] == '3')
        {
            int value;
            cin >> value;
            cout << customStack.get(value) << endl;
        }
        else if (input[0] == '4')
        {
            customStack.undo();
        }
    }

    return 0;
}
