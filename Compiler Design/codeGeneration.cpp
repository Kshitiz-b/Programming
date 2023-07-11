#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to assign precedence to operators
int getPrecedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
string convertToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (isOperator(c))
        {
            while (!s.empty() && isOperator(s.top()) && getPrecedence(s.top()) >= getPrecedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to convert postfix expression to quadruple and machine instructions
void convertToQuadrupleAndMachineInstructions(string postfix)
{
    stack<string> s;
    vector<string> quadruple;
    vector<string> machineInstructions;

    int t1 = 1, t2 = 1; // Temporary variable counter

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            string operand(1, c);
            s.push(operand);
        }
        else if (isOperator(c))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string result1 = "t" + to_string(t1++); // Use register R0, R1, R2, ...
            string result2 = "R" + to_string(t2++);
            quadruple.push_back(string(1, c) + " " + op2 + " " + op1 + " " + result1);
            machineInstructions.push_back("MOV A, " + op2);
            if (c == '+')
                machineInstructions.push_back("ADD A, " + op1);
            else if (c == '-')
                machineInstructions.push_back("SUBB A, " + op1);
            else if (c == '*')
                machineInstructions.push_back("MUL AB, " + op1);
            else if (c == '/')
                machineInstructions.push_back("DIV AB, " + op1);
            machineInstructions.push_back("MOV " + result2 + ", A");

            s.push(result2);
        }
    }

    // Print quadruple
    cout << "Quadruple:" << endl;
    cout << "op arg1 arg2 result\n";
    for (string q : quadruple)
    {
        cout << q << endl;
    }

    // Print machine instructions
    cout << "Machine Instructions:" << endl;
    for (string m : machineInstructions)
    {
        cout << m << endl;
    }
}

int main()
{
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = convertToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    convertToQuadrupleAndMachineInstructions(postfix);

    return 0;
}
