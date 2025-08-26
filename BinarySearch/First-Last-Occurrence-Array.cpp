#include <iostream>
using namespace std;

vector<int> findByLinearSearch(vector<int> &nums, int x)
{
    int first = -1, last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x && first == -1)
        {
            first = i;
        }
        else if (nums[i] == x && first != -1)
        {
            last = i;
        }
    }
    return {first, last};
}
// Binary search using Lower and Upper bound bulid in funcationality
int lowerBound(vector<int> &nums, int x)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= x)
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

int upperBound(vector<int> &nums, int x)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] > x)
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

vector<int> findByBS(vector<int> &nums, int x)
{
    int lb = lowerBound(nums, x);
    int up = upperBound(nums, x);
    if (lb == nums.size() || nums[lb] != x)
    {
        return {-1, -1};
    }
    return {lb, up - 1};
}

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

vector<int> findByBSP(vector<int> &nums, int x)
{
    int f = first(nums, x);
    int l = last(nums, x);
    if (f == nums.size() || nums[f] != x)
    {
        return {-1, -1};
    }
    return {f, l};
}

int main()
{
    vector<int> nums = {1, 3, 5, 67, 123, 125};
    int x = 15;
    vector<int> answer = findByBSP(nums, x);
    for (auto val : answer)
    {
        cout << val << " ";
    }
    return 0;
}