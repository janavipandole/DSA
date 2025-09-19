#include <iostream>
using namespace std;
bool isHappy(int n)
{
    while (true)
    {
        if (n == 1)
            return true;

        int newN = 0;
        while (n > 0)
        {
            int digit = n % 10;
            newN += digit * digit;
            n /= 10;
        }
        n = newN;
        if (n == 1)
            return true;
        if (n / 10 == 0 && n + n < 10)
            return false;
    }
    return false;
}
int main()
{
    int n = 2;
    cout << "Happy Number : " << isHappy(n) << endl;
    return 0;
}