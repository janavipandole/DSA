#include <iostream>
using namespace std;
class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        int num1 = INT_MAX, num2 = INT_MAX;

        for (int i = 0; i < nums1.size(); i++)
        {
            num1 = min(num1, nums1[i]);
            num2 = min(num2, nums2[i]);
        }
        return num2 - num1;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {2, 6, 4}, nums2 = {9, 7, 5};
    cout << "Find the Integer Added to Array I : " << s.addedInteger(nums1, nums2) << endl;
    return 0;
}