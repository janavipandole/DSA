#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    vector<int> nums;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        nums.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        nums.push_back(nums2[j]);
        j++;
    }
    if (nums.size() % 2 != 0)
    {
        double ans = nums[nums.size() / 2];
        return ans;
    }
    int index1 = nums.size() / 2;
    int index2 = index1 - 1;

    double ans = float(nums[index1] + nums[index2]) / 2;

    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << "findMedianSortedArrays : " << findMedianSortedArrays(nums1 ,nums2) << endl;
    return 0;
}