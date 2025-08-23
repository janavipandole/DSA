#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int left = 1, right = x;
    int ans = 1;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    cout << "mySqrt : " << mySqrt(9) << endl;
    return 0;
}