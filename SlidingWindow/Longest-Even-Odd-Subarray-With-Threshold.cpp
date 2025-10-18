#include <iostream>
using namespace std;

class Solution
{
public:
    int longestAlternatingSubarray_Brute(vector<int> &nums, int T)
    {
        int ML = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0 || nums[i] > T) continue;

            int j = i;
            while (j + 1 < nums.size() && nums[j] <= T && nums[j + 1] <= T && nums[j] % 2 != nums[j + 1] % 2)
            {
                j++;
            }

            ML = max(ML, j - i + 1);
        }
        return ML;
    }
    
    int longestAlternatingSubarray_Optimal(vector<int>& nums, int threshold) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int k = 1;
            if(nums[i] % 2 == 0 && nums[i] <= threshold){
                for(;i<nums.size()-1;i++){
                    if(nums[i] % 2 != nums[i + 1] % 2 && nums[i+1] <= threshold){
                        k++;
                        ans = max(ans , k);
                    }
                    else break;
                }
                
                ans = max(ans , k);
            }
            
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2};
    int T = 18;
    cout << "Longest Even Odd Subarray With Threshold : " << s.longestAlternatingSubarray_Brute(nums, T) << endl;
    cout << "Longest Even Odd Subarray With Threshold : " << s.longestAlternatingSubarray_Optimal(nums, T) << endl;

    return 0;
}