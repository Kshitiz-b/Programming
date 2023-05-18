#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct SymbolEntry
{
    std::string name;
    std::string scope;
    std::string type;
    int lineNumber;
};

class SymbolTable
{
private:
    std::unordered_map<std::string, SymbolEntry> symbolMap;

public:
    void insertSymbol(const std::string &name, const std::string &scope, const std::string &type, int lineNumber)
    {
        SymbolEntry entry;
        entry.name = name;
        entry.scope = scope;
        entry.type = type;
        entry.lineNumber = lineNumber;

        symbolMap[name] = entry;
    }

    void displaySymbolTable() const
    {
        std::cout << "Symbol Table:\n";
        std::cout << "----------------------------------------\n";
        std::cout << "| Name\t| Scope\t| Type\t| Line Number |\n";
        std::cout << "----------------------------------------\n";

        for (const auto &pair : symbolMap)
        {
            const SymbolEntry &entry = pair.second;
            std::cout << "| " << entry.name << "\t| " << entry.scope << "\t| " << entry.type << "\t| " << entry.lineNumber << " |\n";
        }

        std::cout << "----------------------------------------\n";
    }
};

int main()
{
    SymbolTable symbolTable;

    std::string program;
    std::string line;

    std::cout << "Enter your program (end with $):\n";

    // Read the program lines until $
    do
    {
        std::getline(std::cin, line);
        program += line + "\n";
    } while (line != "$");

    // Process the program to extract symbols and their attributes
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    int lineNumber = 1;

    while ((pos = program.find(delimiter)) != std::string::npos)
    {
        token = program.substr(0, pos);

        if (token == "int" || token == "float" || token == "double")
        {
            // Symbol declaration line
            std::string type = token;

            // Extract variable names
            while ((pos = program.find(delimiter)) != std::string::npos)
            {
                program.erase(0, pos + delimiter.length());

                if (program[0] == ';' || program[0] == ',')
                {
                    program.erase(0, 1);
                    continue;
                }

                pos = program.find(delimiter);
                token = program.substr(0, pos);

                // Add the variable to the symbol table
                symbolTable.insertSymbol(token, "global", type, lineNumber);
            }
        }

        program.erase(0, pos + delimiter.length());
        lineNumber++;
    }

    // Display the symbol table
    cout << endl;
    symbolTable.displaySymbolTable();

    return 0;
}