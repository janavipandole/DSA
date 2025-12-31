#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int n = expected.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << "Height Checker : " << s.heightChecker(heights) << endl;
    return 0;
}