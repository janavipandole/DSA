#include <iostream>
using namespace std;
// Plain Binary search
int first(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1, first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int last(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1, last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return last;
}

int countFreq(vector<int> &nums, int x)
{
    int f = first(nums, x);
    int l = last(nums, x);
    if (f == nums.size() || nums[f] != x)
    {
        return 0;
    }
    return l - f + 1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3};
    int x = 4;
    cout << "countFreq : " << countFreq(nums, x) << endl;
    return 0;
}
