#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (int n : nums)freq[n]++;

        sort(nums.begin(), nums.end(), [&](int a, int b)
        {
            if (freq[a] == freq[b]) return a > b;    
            return freq[a] < freq[b]; 
        });
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 3, 2};
    cout << "Sort Array by Increasing Frequency : " << endl;
    vector<int> ans = s.frequencySort(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}