#include <iostream>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;

        return n == 1;
    }
    int nthUglyNumber_brute(int n)
    {
        int num = 1;

        while (true)
        {
            if (isUgly(num))n--;
            if (n == 0)return num;
            num++;
        }
        return num;
    }

    int nthUglyNumber_Optimal(int n)
    {
        vector<long long> ugly(n);
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++)
        {
            long long next2 = ugly[i2] * 2;
            long long next3 = ugly[i3] * 3;
            long long next5 = ugly[i5] * 5;

            long long nextUgly = min(next2, min(next3, next5));
            ugly[i] = nextUgly;

            if (nextUgly == next2) i2++;
            if (nextUgly == next3) i3++;
            if (nextUgly == next5) i5++;
        }
        return ugly[n - 1];
    }
};
int main()
{
    Solution s;
    int n = 1407;
    cout << "Ugly Number II : " << s.nthUglyNumber_brute(10) << endl;
    cout << "Ugly Number II : " << s.nthUglyNumber_Optimal(n) << endl;

    return 0;
}