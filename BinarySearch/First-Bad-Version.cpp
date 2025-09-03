#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int num)
{
    if (num >= 4)
        return true;
    return false;
}
// Brute force solution
int firstBadVersionBrute(int n)
{
    int low = 1, high = n;
    for(int i = low; i <= high; i++){
        if(isBadVersion(i)){
            return i;
        }
    }
    return -1;
}
// Optimal solution
int firstBadVersionOptimal(int n)
{
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    cout << "first Bad Version : " << firstBadVersionBrute(5) << endl;
    cout << "first Bad Version : " << firstBadVersionOptimal(5) << endl;
    return 0;
}
