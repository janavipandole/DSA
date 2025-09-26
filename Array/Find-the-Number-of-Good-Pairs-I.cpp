#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int countPairs = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] % (nums2[j] * k) == 0)
                    countPairs++;
            }
        }
        return countPairs;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 4}, nums2 = {1, 3, 4};
    int k = 1;
    cout << "Find the Number of Good Pairs I : " << s.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}