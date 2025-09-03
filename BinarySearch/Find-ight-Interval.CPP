#include <iostream>
using namespace std;
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    vector<int> ans;
    if (intervals.size() == 1)
    {
        return {-1};
    }
    for (int i = 0; i < intervals.size() - 1; i++)
    {
    }
    return ans;
}

int main()
{
    // intervals = [[1,4],[2,3],[3,4]]
    vector<vector<int>> intervals = {{1, 4}, {2, 3}, {3, 4}};
    vector<int> ans = findRightInterval(intervals);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}