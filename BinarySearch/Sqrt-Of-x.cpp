#include <iostream>
using namespace std;

// Brtue force solutions
int mySqrtBrtue(int x)
{
    int ans = 0;
    for (int i = 1; i < x; i++)
    {
        if (i * i > x)
        {
            return ans;
        }
        ans = i;
    }
    return ans;
}
// Optimal solution
int mySqrtOptimal(int x)
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
    cout << "mySqrt Brtue : " << mySqrtBrtue(28) << endl;
    cout << "mySqrt Optimal : " << mySqrtOptimal(28) << endl;

    return 0;
}