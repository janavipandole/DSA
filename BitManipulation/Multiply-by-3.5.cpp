#include <iostream>
using namespace std;
int MultiplyBy(int x)
{
    return (x << 1) + x + (x >> 1);
}
int main()
{
    cout << "Multiply a given Integer with 3.5 : " << MultiplyBy(2) << endl;
    return 0;
}