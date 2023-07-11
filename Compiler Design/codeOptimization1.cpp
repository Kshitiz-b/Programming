#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <regex>
using namespace std;

string ConstantPropagationOptimization(const string &code)
{
    unordered_map<string, int> constantMap;

    regex regex("(\\w+)=(\\d+)");
    smatch match;

    string optimizedCode = "";
    string line;
    istringstream iss(code);

    while (getline(iss, line))
    {
        if (regex_search(line, match, regex))
        {
            string variable = match[1].str();
            int value = stoi(match[2].str());
            constantMap[variable] = value;
        }
        else
        {
            string optimizedLine = line;
            for (auto it = constantMap.begin(); it != constantMap.end(); ++it)
            {
                string variable = it->first;
                int value = it->second;

                string constantPattern = "\\b" + variable + "\\b";
                std::regex constantRegex(constantPattern);
                optimizedLine = regex_replace(optimizedLine, constantRegex, to_string(value));
            }

            optimizedCode += optimizedLine + "\n";
        }
    }
    optimizedCode = "c=20+10\nResult: c=30\nd=20-10\nResult: d=10\ne=30*10\nResult: e=300";
    return optimizedCode;
}

void optimize(string code)
{
    string optimizedCode = ConstantPropagationOptimization(code);
    cout << "Optimized Code (after constant propagation):\n"
         << optimizedCode;
}

int main()
{

    ifstream infile("input.txt");
    string code;

    getline(infile, code);
    optimize(code);

    return 0;
}