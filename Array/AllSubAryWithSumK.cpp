#include <iostream>
#include <vector>
#include <set>
using namespace std;

int allSubAryWithSumKBrute(vector<int> nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int allSubAryWithSumKBetter(vector<int> nums, int k)
{
    int cnt = 0;
    int sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int remove = sum - k;
        cnt += m[remove];
        m[sum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << "all Sub Ary With Sum K Brute cnt : " << allSubAryWithSumKBetter(nums, 3) << endl;
    return 0;
}