#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool findDay(vector<int> &bloomDay, int m, int k, int val)
{
    int cnt = 0, bouquets = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= val)
        {
            cnt++;
        }
        else
        {
            bouquets += (cnt / k);
            cnt = 0;
        }
    }
    bouquets += (cnt / k);
    return bouquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    if ((long long)m * (long long)k > bloomDay.size())
    {
        return -1;
    }

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (findDay(bloomDay, m, k, mid))
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
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    long long m = 2, k = 3;

    cout << "min Days : " << minDays(bloomDay, m, k) << endl;
    return 0;
}