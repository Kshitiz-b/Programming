#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class SymbolTable
{
private:
    std::unordered_map<std::string, int> table;

public:
    void insert(const std::string &symbol, int value)
    {
        table[symbol] = value;
    }

    bool contains(const std::string &symbol)
    {
        return table.find(symbol) != table.end();
    }

    int getValue(const std::string &symbol)
    {
        if (contains(symbol))
        {
            return table[symbol];
        }
        // You can choose how to handle the case when the symbol is not found.
        // Here, we throw an exception.
        throw std::runtime_error("Symbol not found in the table.");
    }
};

int main()
{
    SymbolTable symbolTable;

    symbolTable.insert("x", 10);
    symbolTable.insert("y", 20);
    symbolTable.insert("z", 30);

    std::cout << "Symbol Table:\n";
    std::cout << "x: " << symbolTable.getValue("x") << std::endl;
    std::cout << "y: " << symbolTable.getValue("y") << std::endl;
    std::cout << "z: " << symbolTable.getValue("z") << std::endl;

    if (symbolTable.contains("w"))
    {
        std::cout << "w: " << symbolTable.getValue("w") << std::endl;
    }
    else
    {
        std::cout << "w: Symbol not found in the table." << std::endl;
    }

    return 0;
}