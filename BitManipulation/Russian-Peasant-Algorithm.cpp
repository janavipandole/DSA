#include <iostream>
using namespace std;
int russianPeasantAlgorithm(int a, int b)
{
    int result = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            result += a;
        }
        a <<= 1; // a = a+a
        b >>= 1; // b = b/2
    }
    return result;
}
int main()
{
    cout << "Russian Peasant Algorithm : " << russianPeasantAlgorithm(2, 5) << endl;
    return 0;
}