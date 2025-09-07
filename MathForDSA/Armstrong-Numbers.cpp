#include <iostream>
using namespace std;

bool armstrongNumber(int n)
{
    int dummy = n;
    int sum = 0;

    while (dummy > 0)
    {
        int digit = dummy % 10;
        sum += (digit * digit * digit);
        dummy /= 10;
    }
    return sum == n;
}

int main()
{
    cout << "Armstrong Numbers : " << armstrongNumber(153) << endl;
    return 0;
}