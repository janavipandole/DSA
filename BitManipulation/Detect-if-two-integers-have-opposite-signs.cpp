#include <iostream>
using namespace std;
bool isOpposite(int a, int b)
{
    return (a ^ b) < 0;
}
int main()
{
    cout << "Detect if two integers have opposite signs : " << isOpposite(-5, 5) << endl;
    return 0;
}