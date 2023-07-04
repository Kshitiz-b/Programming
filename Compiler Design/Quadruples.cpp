#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Quadruple
{
    string op;
    string arg1;
    string arg2;
    string result;
};

struct Triple
{
    string op;
    string arg1;
    string arg2;
};

int main()
{
    vector<Quadruple> quadruples;
    vector<Triple> triples;

    string a = "a";
    string b = "b";
    string c = "c";
    string d = "d";
    string x = "x";
    string t1 = "t1";
    string t2 = "t2";
    string t3 = "t3";

    Quadruple quad1 = {"*", a, b, t1};
    Quadruple quad2 = {"-", t1, "", t2};
    Quadruple quad3 = {"+", c, d, t3};
    Quadruple quad4 = {"-", t2, t3, x};
    Quadruple quad5 = {"+", a, b, t1};
    Quadruple quad6 = {"+", t1, c, t2};
    Quadruple quad7 = {"+", t2, d, t3};
    Quadruple quad8 = {"-", t3, x, x};

    Triple triple1 = {"*", a, b};
    Triple triple2 = {"-", t1, t2};
    Triple triple3 = {"+", c, d};
    Triple triple4 = {"-", t2, t3};
    Triple triple5 = {"+", a, b};
    Triple triple6 = {"+", t1, c};
    Triple triple7 = {"+", t2, d};
    Triple triple8 = {"-", t3, x};

    quadruples.push_back(quad1);
    quadruples.push_back(quad2);
    quadruples.push_back(quad3);
    quadruples.push_back(quad4);
    quadruples.push_back(quad5);
    quadruples.push_back(quad6);
    quadruples.push_back(quad7);
    quadruples.push_back(quad8);

    triples.push_back(triple1);
    triples.push_back(triple2);
    triples.push_back(triple3);
    triples.push_back(triple4);
    triples.push_back(triple5);
    triples.push_back(triple6);
    triples.push_back(triple7);
    triples.push_back(triple8);

    cout << "Quadruples:" << endl;
    for (const auto &quad : quadruples)
    {
        cout << quad.op << " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << endl;
    }

    cout << "\nTriples:" << endl;
    for (const auto &triple : triples)
    {
        cout << triple.op << " " << triple.arg1 << " " << triple.arg2 << endl;
    }

    return 0;
}
