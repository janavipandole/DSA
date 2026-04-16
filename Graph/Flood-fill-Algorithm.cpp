#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int initialColor, int i, int j, int n, int m, int color)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != initialColor)return;

        if (initialColor == image[i][j]) image[i][j] = color;

        dfs(image, initialColor, i - 1, j, n, m, color);
        dfs(image, initialColor, i + 1, j, n, m, color);
        dfs(image, initialColor, i, j - 1, n, m, color);
        dfs(image, initialColor, i, j + 1, n, m, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        int n = image.size();
        int m = image[0].size();

        dfs(image, initialColor, sr, sc, n, m, color);

        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    cout << "Flood fill Algorithm : " << endl;

    vector<vector<int>> ans = s.floodFill(image, sr, sc, color);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}