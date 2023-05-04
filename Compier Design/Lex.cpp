#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{ // save "string.txt" file in same folder
    int op_count = 0;
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
        {
            cout << ch << " is a operator" << endl;
            op_count += 1;
        }
    }

    cout << endl
         << "Operator Count:" << op_count << endl;
}