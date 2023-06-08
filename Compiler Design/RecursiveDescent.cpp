#include <iostream>
#include <string>

using namespace std;

string input;
int index = 0;

bool parseE();
bool parseT();
bool parseF();

bool isId(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool match(char c)
{
    if (index < input.length() && input[index] == c)
    {
        index++;
        return true;
    }
    return false;
}

bool parseE()
{
    if (parseT())
    {
        if (match('+') && parseE())
        {
            return true;
        }
        return true;
    }
    return false;
}

bool parseT()
{
    if (parseF())
    {
        if (match('*') && parseT())
        {
            return true;
        }
        return true;
    }
    return false;
}

bool parseF()
{
    if (match('(') && parseE() && match(')'))
    {
        return true;
    }
    if (isId(input[index]))
    {
        index++;
        return true;
    }
    return false;
}

bool parseInput(string str)
{
    input = str;
    index = 0;
    return parseE() && index == input.length();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (parseInput(expression))
    {
        cout << "E = E+T | T\nT = T*F | F\nF = (E) | id \n" << endl;
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}
