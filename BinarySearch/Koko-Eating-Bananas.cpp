#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long EatingSpeed(vector<int> &piles, int hourly)
{
    long long totalHour = 0;

    for (auto pile : piles)
    {
        totalHour += ceil((double)pile / (double)hourly);
    }

    return totalHour;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((EatingSpeed(piles, mid)) <= h)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> piles = {805306368,805306368,805306368};
    int h = 1000000000;

    cout << "minEatingSpeed : " << minEatingSpeed(piles, h) << endl;
    return 0;
}