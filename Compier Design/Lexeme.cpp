#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

int isKeyword(char buffer[])
{
    char keywords[35][10] = {"printf", "auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while", "main", "cout"};
    int i, flag = 0;
    for (i = 0; i < 35; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

bool numeric(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char ch, buffer[15];
    vector<char> operators{'+', '-', '*', '/', '=', '%'};
    vector<char> special{';', '(', ')', '{', '}', '[', ']'};
    int op_count = 0, keyword_count = 0, var_count = 0, const_count = 0;
    vector<string> key, var, constant, literal;
    vector<char> op, sp;

    int num[10];

    FILE *fp;
    int i, j = 0;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        for (i = 0; i < 5; i++)
        {
            if (ch == operators[i])
            {
                op.push_back(ch);
                operators.erase(operators.begin() + i);
            }
        }
        for (i = 0; i < 6; i++)
        {
            if (ch == special[i])
            {
                sp.push_back(ch);
                special.erase(special.begin() + i);
            }
        }

        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n' || ch == '"') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1)
            {
                key.push_back(buffer);
                keyword_count++;
            }
            else
            {
                if (numeric(buffer))
                {
                    constant.push_back(buffer);
                    const_count++;
                }
                else
                {
                    var.push_back(buffer);
                    var_count++;
                }
            }
        }
    }

    printf("\nLexeme of Operator: ");
    int size = op.size();
    for (i = 0; i < size; i++)
    {
        cout << op[i] << " ";
    }

    printf("\nLexeme of Special: ");
    size = sp.size();
    sort(sp.begin(), sp.end());
    for (i = 0; i < size; ++i)
    {
        cout << sp[i] << " ";
    }

    printf("\nLexeme of Keywords: ");
    int size1 = key.size();
    sort(key.begin(), key.end());
    for (i = 0; i < size1; i++)
    {
        if (key[i] != key[i + 1])
            cout << key[i] << " ";
    }

    printf("\nLexeme of Variables: ");
    int size2 = var.size();
    sort(var.begin(), var.end());
    for (i = 0; i < size2; i++)
    {
        if (var[i] != var[i + 1])
            cout << var[i] << " ";
    }

    printf("\nLexeme of Constant: ");
    int size3 = constant.size();
    for (i = 0; i < size3; i++)
    {
        cout << constant[i] << " ";
    }

    printf("\nLexeme of Literals: ");
    size = literal.size();
    for (i = 0; i < size; i++)
    {
        cout << literal[i] << " ";
    }

    fclose(fp);
    return 0;
}