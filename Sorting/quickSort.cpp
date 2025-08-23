#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &nums, int low, int high)
{
    int elem = nums[low];
    int j = low;
    //{3, 2, 1, 4, 7, 9, 6, 5}
    for (int i = low + 1; i <= high; i++)
    {
        if (nums[i] < elem)
        {
            j++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[j], nums[low]);
    return j;
}

void qs(vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = findPivot(nums, low, high);
    qs(nums, low, pivot - 1);
    qs(nums, pivot + 1, high);
}

void quickSort(vector<int> &nums)
{
    qs(nums, 0, nums.size() - 1);
    return;
}

int main()
{
    vector<int> nums = {4, 6, 2, 5, 7, 9, 1, 3};
    quickSort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}