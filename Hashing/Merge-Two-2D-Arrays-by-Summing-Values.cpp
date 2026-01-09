#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i][0] == nums2[j][0])
            {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0])
            {
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else if (nums1[i][0] > nums2[j][0])
            {
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while (i < nums1.size())
        {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while (j < nums2.size())
        {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}, {5, 5}}, nums2 = {{1, 4}, {3, 2}, {4, 1}};
    cout << "Merge Two 2D Arrays by Summing Values : " << endl;
    vector<vector<int>> ans = s.mergeArrays(nums1, nums2);
    for (auto num : ans)
    {
        cout << num[0] << " " << num[1] << endl;
    }
    return 0;
}