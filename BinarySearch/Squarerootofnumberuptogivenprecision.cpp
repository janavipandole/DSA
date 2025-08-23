#include <iostream>
#include <iomanip>
using namespace std;
double squareRoot(int n, int p)
{
    double ans = 1;

    int low = 1, high = n;

    while (low <= high)
    {
        double mid = (low + high) / 2;

        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Step 2: Linear search for decimal part
    double increment = 0.1;
    for (int i = 0; i < p; i++)
    {
        while ((ans + increment) * (ans + increment) <= n)
        {
            ans += increment;
        }
        increment /= 10;
    }

    return ans;
}
int main()
{
    int n = 50;
    int p = 3;
    cout << fixed << setprecision(p);
    cout << "squareRoot : " << squareRoot(n, p) << endl;
    return 0;
}