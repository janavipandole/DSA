#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int num)
{
    if (num >= 4)return true;
    return false;
}
int firstBadVersion(int n)
{
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main()
{
    cout << "first Bad Version : " << firstBadVersion(5) << endl;
    return 0;
}
