#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    for (int i = min(a, b); i > 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}
// Euclidean Algorithm
int gcdEA(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a > 0 ? a : b;
}
int main()
{
    int a = 60, b = 36;
    cout << "GCD of two numbers : " << gcdEA(a, b) << endl;
    return 0;
}
