#include <iostream>
#include <math.h>
using namespace std;
// Brute force approch
vector<int> kWeakestRowsBrute(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> nums;
    for (int i = 0; i < mat.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            sum += mat[i][j];
            if (mat[i][j] == 0)
                break;
        }
        nums.push_back({sum, i});
    }
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int cnt = 0;
    for (auto val : nums)
    {
        if (cnt < k)
        {
            cnt++;
            ans.push_back(val.second);
        }
    }
    return ans;
}
// Optimal Approch
vector<int> kWeakestRowsOptimal(vector<vector<int>> &mat, int k)
{
    int n = mat[0].size();
    for (int i = 0; i < mat.size(); i++)
    {
        mat[i].push_back(i);
    }
    sort(mat.begin(), mat.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = mat[i][n];
    }
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    // vector<int> ans = kWeakestRowsBrute(nums, 3);
    vector<int> ans = kWeakestRowsOptimal(nums, 3);
    for (auto an : ans)
    {
        cout << an << " ";
    }
    cout << endl;
    return 0;
}