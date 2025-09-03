#include <iostream>
using namespace std;
// Brute force solution
bool isPerfectSquareBrute(int num)
{
    int low = 1;
    int high = num;

    for (int i = low; i <= high; i++)
    {
        if (i * i == num)
            return true;
        if (i * i > num)
            return false;
    }
    return false;
}
// Optimal solution
bool isPerfectSquareOptimal(int num)
{
    int low = 1;
    int high = num;
   while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long)mid * (long long)mid == num) return true;
        if ((long long)mid * mid > num) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
int main()
{
    cout << "Is Perfect Square : " << isPerfectSquareBrute(1) << endl;
    cout << "Is Perfect Square : " << isPerfectSquareOptimal(1) << endl;

    return 0;
}