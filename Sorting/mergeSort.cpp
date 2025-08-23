#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

}
void MS(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    MS(nums, low, mid);
    MS(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
void mergeSort(vector<int> &nums)
{
    MS(nums, 0, nums.size() - 1);
    return;
}

int main()
{
    vector<int> nums = {3, 1, 2, 4, 1, 5, 6, 2, 4};
    mergeSort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}