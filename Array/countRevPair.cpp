#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        int i = low, j = mid + 1;
        vector<int> temp;

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
        return;
    }
    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > (2 * nums[j]))
            {
                j++;
            }
            cnt += j - (mid + 1);
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
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};
    cout << "count reverse pairs : " << s.mergeSort(nums, 0, nums.size() - 1) << endl;
    return 0;
}