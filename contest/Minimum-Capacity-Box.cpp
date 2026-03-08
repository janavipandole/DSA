#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        int minIndex = INT_MAX;
        int minCap = INT_MAX;
        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] >= itemSize && capacity[i] < minCap)
            {
                minCap = capacity[i];
                minIndex = i;
            }
        }
        if (minIndex == INT_MAX)
        {
            return -1;
        }
        return minIndex;
    }
};
int main()
{
    Solution s;
    vector<int> capacity = {1, 5, 3, 7};
    int itemSize = 3;
    cout << "Minimum Capacity Box : " << s.minimumIndex(capacity, itemSize) << endl;
    return 0;
}