#include <iostream>
using namespace std;

class Solution
{
public:
    //Brute force solution
    int longestOnes_Brute(vector<int> &nums, int k)
    {
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            for(int j = i; j < nums.size(); j++){
                if(nums[j] == 0) cnt++;
                if(cnt > k) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    //Better solution
    int longestOnes_Better(vector<int> &nums, int k)
    {
        int maxLen = 0, start = 0, cntZero = 0;
        for(int end = 0; end < nums.size(); end++){
            if(nums[end] == 0) cntZero++;

            while(cntZero > k){
                if(nums[start] == 0) cntZero--;
                start++; 
            }
            if(cntZero <= k)  maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }

    //Optimal solution
    int longestOnes_Optimal(vector<int> &nums, int k)
    {
        int maxLen = 0, start = 0, cntZero = 0,end = 0;
        while(end< nums.size()){
            if(nums[end] == 0) cntZero++;

            if(cntZero > k){
                if(nums[start] == 0) cntZero--;
                start++; 
            }
            if(cntZero <= k)  maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen; 
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout<<"Max Consecutive Ones III : "<<s.longestOnes_Brute(nums, k)<<endl;
    cout<<"Max Consecutive Ones III : "<<s.longestOnes_Better(nums, k)<<endl;
    cout<<"Max Consecutive Ones III : "<<s.longestOnes_Optimal(nums, k)<<endl;

    return 0;
}