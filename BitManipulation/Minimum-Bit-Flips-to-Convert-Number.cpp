#include <iostream>
using namespace std;
// Bit form optimal soltion
int countBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
int minBitFlips(int start, int goal)
{
    int ans = start^goal;
    return countBits(ans);
}
int main()
{
    int start = 3, goal = 4;
    cout << "Minimum Bit Flips to Convert Number : " << minBitFlips(start, goal) << endl;
    return 0;
}