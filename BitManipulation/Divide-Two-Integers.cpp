#include <iostream>
using namespace std;
// Brute force solution
int divide(int dividend, int divisor)
{
    long long cnt = 0, add = 0;
    while (add + divisor <= dividend)
    {
        add += divisor;
        cnt++;
    }
    return cnt;
}
// Optimal solution
int divideOptimal(int dividend, int divisor)
{
    bool sign = true;
    if (dividend < 0 && divisor > 0)
        sign = false;
    if (divisor < 0 && dividend >= 0)
        sign = false;

    long long dd = abs((long long)dividend), ds = abs((long long)divisor);
    if (dd == ds)
        return sign ? 1 : -1;

    long long ans = 0;
    while (dd >= ds)
    {

        int cnt = 0;
        while (dd >= (ds << (cnt + 1)))
        {
            cnt++;
        }
        dd -= (ds << cnt);
        ans += (1 << cnt);
    }
    if (ans == (1 << 31) && sign == true)
        return INT_MAX;
    if (ans == (1 << 31) && sign == false)
        return INT_MIN;
    return sign ? ans : (-ans);
}
int main()
{
    int dividend = -2147483648, divisor = -1;
    cout << "Divide Two Integers : " << divide(dividend, divisor) << endl;
    cout << "Divide Two Integers : " << divideOptimal(dividend, divisor) << endl;
    return 0;
}