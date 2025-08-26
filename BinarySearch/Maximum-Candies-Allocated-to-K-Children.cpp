#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool candiesAllocation(vector<int> &candies, long long k, long long maxAllocation)
{
    long long child = 0;
    for (auto cand : candies)
    {
        child += cand / maxAllocation;
    }
    return child >= k;
}

int maximumCandies(vector<int> &candies, long long k)
{
    long long st = 1;
    long long end = *max_element(candies.begin(), candies.end());
    while (st <= end)
    {
        long long mid = st + (end - st) / 2;
        if (candiesAllocation(candies, k, mid))
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return end;
}

int main()
{
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    cout << "maximum Candies : " << maximumCandies(candies, k) << endl;
    return 0;
}