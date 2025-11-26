#include <iostream>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;

        for (int i = 0; i < stones.size(); i++)
        {
            maxHeap.push(stones[i]);
        }

        while (maxHeap.size() > 1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if (x != y)maxHeap.push(y - x);
        }
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
int main()
{
    Solution s;
    vector<int> arr = {2,7,4,1,8,1};
    cout << "Last Stone Weight : " << s.lastStoneWeight(arr) << endl;
    return 0;
}