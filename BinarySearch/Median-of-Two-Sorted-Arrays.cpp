#include <iostream>
using namespace std;
// Brute force solution
double findMedianSortedArraysBrute(vector<int> &nums1, vector<int> &nums2)
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
// Better solution
double findMedianSortedArraysBetter(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size(), n = (n1 + n2);
    int index1 = n / 2, index2 = index1 - 1, cnt = 0, elem1 = -1, elem2 = -1;
    while (i < n1 && j < n2)
    {
        if (elem1 != -1 && elem2 != -1)
            break;
        if (nums1[i] < nums2[j])
        {
            if (cnt == index1)
            {
                elem1 = nums1[i];
            }
            if (cnt == index2)
            {
                elem2 = nums1[i];
            }
            i++;
            cnt++;
        }
        else
        {
            if (cnt == index1)
            {
                elem1 = nums2[j];
            }
            if (cnt == index2)
            {
                elem2 = nums2[j];
            }
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (elem1 != -1 && elem2 != -1)
            break;
        if (cnt == index1)
        {
            elem1 = nums1[i];
        }
        if (cnt == index2)
        {
            elem2 = nums1[i];
        }
        i++;
        cnt++;
    }
    while (j < n2)
    {
        if (elem1 != -1 && elem2 != -1)
            break;
        if (cnt == index1)
        {
            elem1 = nums2[j];
        }
        if (cnt == index2)
        {
            elem2 = nums2[j];
        }
        cnt++;
        j++;
    }
    if (n % 2 != 0)
    {
        return double(elem1);
    }

    double ans = double(elem1 + elem2) / 2;

    return ans;
}

// Optimal solution
double findMedianSortedArraysOptimal(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) findMedianSortedArraysOptimal(nums2, nums1); // Always try to tak first as smalest array
    int low = 0;
    int high = n1;
    int n = n1 + n2;
    int leftHalf = (n1 + n2 + 1) / 2; // for odd size also manage
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = leftHalf - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if(mid1 < n1) r1 = nums1[mid1]; //r1 is valid so place else remain it INT_MAX
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1-1]; 
        if(mid2 - 1 >= 0) l2 = nums2[mid2-1]; 

        // If we get valid symmerty
        if(l1 < r2 && l2 < r1){
            // odd size array
            if(n%2 != 0) return  max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0.0;
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << "find Median Sorted Arrays Brute : " << findMedianSortedArraysBrute(nums1, nums2) << endl;
    cout << "find Median Sorted Arrays Better : " << findMedianSortedArraysBetter(nums1, nums2) << endl;
    cout << "find Median Sorted Arrays Optimal : " << findMedianSortedArraysOptimal(nums1, nums2) << endl;

    return 0;
}