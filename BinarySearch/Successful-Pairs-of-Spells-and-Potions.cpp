#include <iostream>
using namespace std;
// Brute force solutions
vector<int> successfulPairsBrute(vector<int> &spells, vector<int> &potions, long long success)
{
    vector<int> ans(spells.size());
    sort(potions.begin(), potions.end());
    for (long long i = 0; i < spells.size(); i++)
    {
        long long cnt = 0;
        for (long long j = 0; j < potions.size(); j++)
        {
            if (spells[i] * potions[j] > success)
            {
                cnt += potions.size() - j;
                break;
            }
        }
        ans[i] = cnt;
    }

    return ans;
}
// Optimal soltuion
int getTarget(vector<int> &nums, long long n, long long success)
{
    long long low = 0;
    long long high = nums.size() - 1;
    long long answer = nums.size();
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (nums[mid] * n >= success)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return answer;
}
vector<int> successfulPairsOptimal(vector<int> &spells, vector<int> &potions, long long success)
{
    vector<int> ans(spells.size());
    sort(potions.begin(), potions.end());

    for (int i = 0; i < spells.size(); i++)
    {
        ans[i] = potions.size() - getTarget(potions, spells[i], success);
    }

    return ans;
}
int main()
{
    vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
    int success = 7;
    vector<int> ans = successfulPairsBrute(spells, potions, success);
    // vector<int> ans = successfulPairsOptimal(spells, potions, success);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}