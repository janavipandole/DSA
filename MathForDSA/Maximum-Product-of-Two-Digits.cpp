#include <iostream>
#include <set>
using namespace std;

int maxProduct(int n)
{
    int d1 = INT_MIN, d2 = INT_MIN;
    while (n > 0)
    {
        int digit = (n % 10);
        if (d1 < digit)
        {
            d2 = d1;
            d1 = digit;
        }else{
            d2 = max(d2, digit);
        }
        n /= 10;
    }

    return d1 * d2;
}
int main()
{
    int n = 124;
    cout << "Maximum Product of Two Digits : " << maxProduct(n) << endl;
    return 0;
}