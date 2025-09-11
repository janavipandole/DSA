#include <iostream>
using namespace std;
bool isPrime(int num)
{
    if (num == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}
int countPrimeSetBits(int left, int right)
{
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        if (isPrime(__builtin_popcount(i)))
            cnt++;
    }
    return cnt;
}
int main()
{
    int left = 6, right = 10;

    cout << "Prime Number of Set Bits in Binary Representation : " << countPrimeSetBits(left, right) << endl;
    return 0;
}