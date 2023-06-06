#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

struct Symbol
{
    int line;
    std::string scope;
    std::string dataType;
};

void constructSymbolTable(const std::string &filename)
{
    std::ifstream file(filename);
    std::unordered_map<std::string, Symbol> symbolTable;
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line))
    {
        lineNumber++;
        std::string token;
        std::istringstream iss(line);

        while (iss >> token)
        {
            // Check if token is a valid symbol (you can modify this condition as per your requirements)
            if (isalpha(token[0]))
            {
                // Check if the symbol already exists in the symbol table
                if (symbolTable.find(token) != symbolTable.end())
                {
                    // Symbol already exists, update its information
                    symbolTable[token].line = lineNumber;
                    // Update other information as needed
                }
                else
                {
                    // Symbol doesn't exist, add it to the symbol table
                    Symbol symbol;
                    symbol.line = lineNumber;
                    // Assign other information as needed
                    symbolTable[token] = symbol;
                }
            }
        }
    }

    // Print the symbol table
    for (const auto &entry : symbolTable)
    {
        std::cout << "Symbol: " << entry.first << ", Line: " << entry.second.line << std::endl;
        // Print other information as needed
    }

    file.close();
}

int main()
{
    std::string filename = "sample.txt"; // Provide the path to your input text file
    constructSymbolTable(filename);
    return 0;
}
