#include <iostream>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int row = strs.size();
        int col = strs[0].size();
        int count = 0;
        for (int c = 0; c < col; c++)
        {
            for (int r = 1; r < row; r++)
            {
                if (strs[r][c] < strs[r - 1][c])
                {
                    count++; // delete this column
                    break;   // move to next column
                }
            }
        }

        return count;
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"cba", "daf", "ghi"};
    cout << "Delete Columns to Make Sorted : " << s.minDeletionSize(strs) << endl;
    return 0;
}