#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool Divisor(vector<int> &nums, int threshold, int div)
{
    int sum = 0;

    for (auto num : nums)
    {
        sum += ceil((double)num / (double)div);
    }
    return sum <= threshold;
}
int smallestDivisorBrute(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    for (int i = low; i < high; i++)
    {
        if (Divisor(nums, threshold, i))
        {
            return i;
        }
    }
    return -1;
}
int smallestDivisorOptimal(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (Divisor(nums, threshold, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "smallest Divisor Brute : " << smallestDivisorBrute(nums, threshold) << endl;
    cout << "smallest Divisor Optimal : " << smallestDivisorOptimal(nums, threshold) << endl;
    return 0;
}