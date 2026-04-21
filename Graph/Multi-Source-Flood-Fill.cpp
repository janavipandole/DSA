#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources)
    {
        vector<vector<int>> answer(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int changeRow[] = {1, -1, 0, 0};
        int changeCol[] = {0, 0, 1, -1};

        for (auto source : sources)
        {
            int r = source[0], c = source[1], val = source[2];

            answer[r][c] = val;
            q.push({{r, c}, 0});
        }

        while (!q.empty())
        {
            auto row = q.front().first.first;
            auto col = q.front().first.second;
            auto t = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + changeRow[i];
                int newCol = col + changeCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && answer[newRow][newCol] < answer[row][col])
                {
                    answer[newRow][newCol] = answer[row][col];
                    q.push({{newRow, newCol}, t + 1});
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    int n = 3, m = 3;
    vector<vector<int>> sources = {{0, 0, 1}, {2, 2, 2}};
    cout << "Multi Source Flood Fill : " << endl;
    vector<vector<int>> answer = s.colorGrid(n, m, sources);
    for (auto nums : answer)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}