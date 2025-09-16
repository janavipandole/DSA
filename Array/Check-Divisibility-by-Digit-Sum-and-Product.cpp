#include <iostream>
using namespace std;
bool checkDivisibility(int n)
{
    int digitSum = 0, digitProduct = 1;
    int copy = n;

    while (copy > 0)
    {
        int digit = copy % 10;

        digitSum += digit;
        digitProduct *= digit;

        copy /= 10;
    }

    int sum = digitSum + digitProduct;
    if (n % sum == 0)
        return true;
    return false;
}
int main()
{
    int n = 99;
    cout << "Check Divisibility by Digit Sum and Product : " << checkDivisibility(n) << endl;
    return 0;
}