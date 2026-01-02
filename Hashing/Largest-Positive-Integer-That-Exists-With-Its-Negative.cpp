#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        unordered_map<int, int> hash;
        for (auto num : nums)
        {
            hash[num]++;
        }

        for(auto num : nums){
            if(hash.find(num) != hash.end() && hash.find(-1 * num) != hash.end()){
                ans = max(ans, num);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1, 2, -3, 3};
    cout << "Largest Positive Integer That Exists With Its Negative : " << s.findMaxK(nums) << endl;
    return 0;
}