#include <iostream>
using namespace std;
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    vector<int> ans(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int sum = queries[i];
        int cnt = 0;
        int currentSum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (sum < nums[j])
                continue;

            currentSum += nums[j];
            cnt++;
            if (currentSum <= sum)
            {
                ans[i] = cnt;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};
    sort(nums.begin(), nums.end());
    vector<int> ans = answerQueries(nums, queries);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}