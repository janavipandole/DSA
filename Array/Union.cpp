#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> unionInArrayBrute(vector<int> nums1, vector<int> nums2)
    {
        set<int> s;
        for (int i = 0, j = 0; i < nums1.size() || j < nums2.size(); i++, j++)
        {
            s.insert(nums1[i]);
            s.insert(nums2[j]);
        }
        int i = 0;
        nums1.resize(s.size());
        for (int val : s)
        {
            nums1[i] = val;
            i++;
        }
        return nums1;
    }
    vector<int> unionInArrayOptimal(vector<int> nums1, vector<int> nums2)
    {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] != nums2[j])
            {
                if (ans.size() == 0 || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }

                i++;
            }
            else
            {
                if (ans.size() == 0 || ans.back() != nums2[j])
                {
                    ans.push_back(nums2[j]);
                }
                j++;
            }
        }
        while (i < nums1.size())
        {
            if (ans.size() == 0 || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
        }
        while (j < nums2.size())
        {
            if (ans.size() == 0 || ans.back() != nums2[j])
            {
                ans.push_back(nums2[j]);
            }
            j++;
        }
        return ans;
    }

    vector<int> intersetionInArrayBrute(vector<int> nums1, vector<int> nums2)
    {
        vector<int> visited(nums2.size(), 0);
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {

            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j] && visited[j] == 0)
                {
                    ans.push_back(nums1[i]);
                    visited[j] = -1;
                    break;
                }
                if (nums2[j] > nums1[i])
                    break;
            }
        }
        return ans;
    }
    vector<int> intersetionInArrayOptimal(vector<int> num1, vector<int> num2)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < num1.size() && j < num2.size())
        {
            if (num1[i] < num2[j])
            {
                i++;
            }
            else if (num1[i] > num2[j])
            {
                j++;
            }
            else
            {
                ans.push_back(num1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 2, 3};
    vector<int> nums2 = {2, 3, 4, 5, 9};

    vector<int> ans = s.intersetionInArrayOptimal(nums1, nums2);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}