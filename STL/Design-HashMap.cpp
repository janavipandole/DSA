#include <iostream>
using namespace std;
vector<pair<bool, int>> table;
void put(int key, int value)
{
    table[key] = {true, value};
}

int get(int key)
{
    return table[key].second;
}

void remove(int key)
{
    table[key] = {false, -1};
}
int main()
{
    return 0;
}