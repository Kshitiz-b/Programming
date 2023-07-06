#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

unordered_map<string, int> symbolTable; // To store variable values

// Function to evaluate an expression
int evaluateExpression(string expr) {
    stringstream ss(expr);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    int result = 0;
    if (tokens.size() == 1 && isalpha(tokens[0][0])) {
        result = symbolTable[tokens[0]];
    } else {
        int leftOperand = stoi(tokens[0]);
        char op = tokens[1][0];
        int rightOperand = stoi(tokens[2]);

        switch (op) {
            case '+':
                result = leftOperand + rightOperand;
                break;
            case '-':
                result = leftOperand - rightOperand;
                break;
            case '*':
                result = leftOperand * rightOperand;
                break;
            case '/':
                result = leftOperand / rightOperand;
                break;
        }
    }

    return result;
}

// Function to optimize the code
void optimizeCode(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found." << endl;
        return;
    }

    vector<string> codeLines;
    string line;
    while (getline(file, line)) {
        codeLines.push_back(line);
    }
    file.close();

    // Step 1: Constant Propagation
    cout << "After constant propagation:" << endl;
    for (const string& codeLine : codeLines) {
        string updatedLine = codeLine;

        size_t equalsPos = codeLine.find('=');
        if (equalsPos != string::npos) {
            string variable = codeLine.substr(0, equalsPos);
            size_t exprStartPos = equalsPos + 1;
            string expr = codeLine.substr(exprStartPos + 1);

            int result = evaluateExpression(expr);

            // Update symbol table
            symbolTable[variable] = result;

            // Update code line
            updatedLine = variable + "=" + to_string(result);
        }

        cout << updatedLine << endl;
    }

    // Step 2: Eliminate Common Subexpressions and Dead Code Elimination
    cout << "\nAfter eliminating common subexpressions and dead code:" << endl;

    unordered_map<string, string> expressionMap;
    vector<string> optimizedCode;
    for (const string& codeLine : codeLines) {
        size_t equalsPos = codeLine.find('=');
        if (equalsPos != string::npos) {
            string variable = codeLine.substr(0, equalsPos);
            size_t exprStartPos = equalsPos + 1;
            string expr = codeLine.substr(exprStartPos + 1);

            if (expressionMap.find(expr) != expressionMap.end()) {
                // Common subexpression found, eliminate and replace with the variable
                string commonVar = expressionMap[expr];
                string updatedLine = variable + "=" + commonVar;

                optimizedCode.push_back(updatedLine);
            } else {
                // New expression, evaluate and update symbol table
                int result = evaluateExpression(expr);
                symbolTable[variable] = result;

                expressionMap[expr] = variable;

                optimizedCode.push_back(codeLine);
                cout << codeLine << endl;
            }
        } else {
            optimizedCode.push_back(codeLine);
            cout << codeLine << endl;
        }
    }

    // Print optimized code
    cout << "\nOptimized code:" <<endl;
    for (const string& codeLine : optimizedCode) {
        cout << codeLine << endl;
    }
}

int main() {
    string filename = "input1.txt";
    optimizeCode(filename);

    return 0;
}
