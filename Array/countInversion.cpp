#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
int merge(vector<int> &nums, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<int> temp;

    int cnt = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            cnt += (mid - i + 1);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(nums[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }

    int mid = (high + low) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);
    return cnt;
}

int countInversion(vector<int> &nums, int n)
{
    return mergeSort(nums, 0, n - 1);
}
};
int main()
{
    Solution s;
    vector<int> nums = {5, 3, 2, 4, 1};
    cout << "count Inversion : " << s.countInversion(nums, nums.size()) << endl;
    return 0;
}