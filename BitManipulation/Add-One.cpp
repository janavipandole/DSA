#include <iostream>
using namespace std;
int addOne(int n)
{
    return n ^ 1;
}
int main()
{
    cout << "Add 1 to a given number : " << addOne(6) << endl;
    return 0;
}