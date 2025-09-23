#include <iostream>
#include <vector>
using namespace std;

vector<bool> table(1e6 + 1, false);

void add(int key)
{
    table[key] = true;
}

void remove(int key)
{
    table[key] = false;
}

bool contains(int key)
{
    return table[key];
}

int main()
{
    add(2);
    add(1);
    add(2);
    remove(2);
    cout << contains(2) << endl;
    return 0;
}