#include <iostream>
using namespace std;
// Intger form
int hammingWeightInt(int n)
{
    int num = n;
    int cnt = 0;
    while (num > 0)
    {
        if (num % 2 == 1)
        {
            cnt++;
        }
        num /= 2;
    }
    return cnt;
}
// Bit form Brute force soltion
int hammingWeightBruteBit(int n)
{
    int num = n;
    int cnt = 0;
    while (num > 1)
    {
        cnt += n & 1;
        num = num >> 1;
    }
    return cnt;
}
// Bit form optimal soltion
int hammingWeightOptimalBit(int n)
{
    int cnt = 0;
    int num = n;
    while (num != 0)
    {
        num = (num & (num - 1));
        cnt++;
    }
    return cnt;
}

int main()
{
    cout << "In-Bulid function to count set bit : " << __builtin_popcount(11) << endl;
    cout << "hamming Weight Int : " << hammingWeightInt(11) << endl;
    cout << "hamming Weight Bit : " << hammingWeightBruteBit(11) << endl;
    cout << "hamming Weight Bit : " << hammingWeightOptimalBit(11) << endl;

    return 0;
}