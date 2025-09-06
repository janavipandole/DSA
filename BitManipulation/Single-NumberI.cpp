#include <iostream>
using namespace std;
// brute force solution
int singleNumberBrute(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    for(auto num : nums) mpp[num]++;

    for(auto &[val , cnt] : mpp){
        if(cnt == 1) return val;
    }
    return -1;
}
// Optimal solution
int singleNumberOptimal(vector<int> &nums)
{
    int ans = 0;
    for (int value : nums)
    {
        ans ^= value;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 1, 4, 5, 4, 5};
    cout << "Single Number : " << singleNumberBrute(nums) << endl;
    cout << "Single Number : " << singleNumberOptimal(nums) << endl;

    return 0;
}