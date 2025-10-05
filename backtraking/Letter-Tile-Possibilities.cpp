#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    void backtrack(int &count, string &tiles, vector<bool> &used, string current)
    {
        if (!current.empty())
        {
            count++;
        }

        unordered_set<char> s;
        for (int i = 0; i < tiles.size(); ++i)
        {
            if (used[i] || s.count(tiles[i]))
            {
                continue;
            }

            used[i] = true;
            s.insert(tiles[i]);
            backtrack(count, tiles, used, current + tiles[i]);
            used[i] = false;
        }
    }
    int numTilePossibilities(string tiles)
    {
        int count = 0;
        vector<bool> used(tiles.size(), false);
        backtrack(count, tiles, used, "");
        return count;
    }
};
int main()
{
    Solution s;
    string tiles = "AAABBC";

    cout << "Letter Tile Possibilities : " << s.numTilePossibilities(tiles) << endl;

    return 0;
}