#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int revNum(int num){
        int newNum = 0;

        while(num > 0){
            int digit = num % 10;

            newNum = newNum * 10 + digit;

            num /= 10;
        }
        return newNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return -1;

        unordered_map<int, int> hash;
        int minDist = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){
                minDist = min(minDist, abs(i - hash[nums[i]]));
            }
            hash[revNum(nums[i])] = i;
        }

        return minDist == INT_MAX ? -1 :minDist ;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {120,21};
    cout << "Minimum Absolute Distance Between Mirror Pairs : " << s.minMirrorPairDistance(nums) << endl;
    return 0;
}