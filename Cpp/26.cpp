#include <iostream>
using namespace std;

class DM
{
public:
    float m;
    float cm;

    readdata()
    {
        cout << "Enter m and cm: ";
        cin >> m >> cm;
    }

    friend void addition();
};

class DB
{
public:
    float feet;
    float inch;
    float ft;
    float in;

    readdata()
    {
        cout << "Enter feet and inch: ";
        cin >> feet >> inch;
    }

    friend void addition(DM dm, DB db);
};

void addition(DM dm, DB db)
{
    db.ft = 0.3048 * db.feet;
    db.in = 2.54 * db.inch;

    dm.m += db.ft;
    dm.cm += db.in;

    cout << "\nThe total m is: " << dm.m;
    cout << "\nThe total cm is: " << dm.cm;
}

int main()
{
    DM dm;
    dm.readdata();

    DB db;
    db.readdata();

    addition(dm, db);
    return 0;
}