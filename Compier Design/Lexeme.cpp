#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <ctype.h>
using namespace std;

int isKeyword(char buffer[])
{
    char keywords[34][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while", "main", "printf"};
    int i, flag = 0;
    for (i = 0; i < 34; i++)
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

vector<char> removeDuplicate(vector<char> str, int n)
{
    unordered_map<char, int> exists;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (exists[str[i]] == 0)
        {
            str[index++] = str[i];
            exists[str[i]]++;
        }
    }
    return str;
}
vector<string> removeDuplicate(vector<string> str, int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (str[i] == str[j])
                break;

        if (j == i)
            str[index++] = str[i];
    }

    return str;
}

int main()
{
    char ch, buffer[15], operators[] = "+-*/=%", special[] = ";(){}[]";
    int op_count = 0, keyword_count = 0, var_count = 0, const_count = 0;
    vector<string> key, var, constant;
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
        for (i = 0; i < 7; i++)
        {
            if (ch == operators[i])
            {
                op.push_back(ch);
            }
        }
        for (i = 0; i < 8; i++)
        {
            if (ch == special[i])
            {
                sp.push_back(ch);
            }
        }

        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
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
    size = sp.size();
    printf("\nLexeme of Special: ");
    removeDuplicate(sp, size);
    for (i = 0; i < size; ++i)
    {
        cout << sp[i] << " ";
    }

    printf("\nLexeme of keywords: ");
    int size1 = key.size();
    for (i = 0; i < size1; i++)
    {
        cout << key[i] << " ";
    }

    printf("\nLexeme of variables: ");
    int size2 = var.size();
    removeDuplicate(var, size2);
    for (i = 0; i < size2; i++)
    {
        cout << var[i] << " ";
    }

    printf("\nLexeme of constant: ");
    int size3 = constant.size();
    for (i = 0; i < size3; i++)
    {
        cout << constant[i] << " ";
    }

    fclose(fp);
    return 0;
}