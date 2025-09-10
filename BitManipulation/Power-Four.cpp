#include <iostream>
using namespace std;
int isPowerOfFour(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    while (n != 1)
    {
        if (n % 4 != 0)
        {
            return 0;
        }
        n = n / 4;
    }
    return 1;
}
int main()
{
    cout << "Find whether a given number is a power of 4 or not : " << isPowerOfFour(64) << endl;
    return 0;
}