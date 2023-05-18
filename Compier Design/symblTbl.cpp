#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

struct SymbolTableEntry
{
    std::string variable_name;
    std::string type;
    int size;
    std::string *address;
    std::string scope;
    int line_num;
};
std::vector<SymbolTableEntry> createSymbolTable(const std::string &input_source_code)
{
    std::vector<SymbolTableEntry> symbol_table;
    int current_line_num = 1;
    std::regex variable_declaration_regex(R"(\bint\s+(\w+)\s*=\s*(\w+)\b)");
    std::istringstream input_stream(input_source_code);
    std::string line;
    while (std::getline(input_stream, line))
    {
        std::smatch match;
        if (std::regex_search(line, match, variable_declaration_regex))
        {
            SymbolTableEntry entry;
            entry.variable_name = match[1].str();
            entry.type = "int";
            entry.size = sizeof(int);
            entry.address = new std::string(entry.variable_name);
            entry.scope = "local";
            entry.line_num = current_line_num;
            symbol_table.push_back(entry);
        }
        current_line_num++;
    }

    return symbol_table;
}

int main()
{
    std::ifstream inputFile("sample.txt");
    if (!inputFile)
    {
        std::cerr << "Error: Failed to open the input file." << std::endl;
        return 1;
    }

    std::string input_source_code((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::vector<SymbolTableEntry> symbol_table = createSymbolTable(input_source_code);

    // Display the symbol table entries
    std::cout << "VARIABLES\tTYPE\tSIZE\tADDRESS\t\tSCOPE\tLINE_NUM\n";
    for (const auto &entry : symbol_table)
    {
        std::cout << entry.variable_name << "\t\t" << entry.type << "\t" << entry.size << "\t" << entry.address << "\t" << entry.scope << "\t" << entry.line_num << std::endl;
    }

    return 0;
}