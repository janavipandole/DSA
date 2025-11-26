#include <iostream>
using namespace std;
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> maxHeap;

        for (int i = 0; i < piles.size(); i++)
        {
            maxHeap.push(piles[i]);
        }

        while (k--)
        {
            int x = maxHeap.top();
            maxHeap.pop();
            x = ceil(x / 2.0);
            maxHeap.push(x);
        }
        int sum = 0;
        while (maxHeap.size() > 0)
        {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> piles = {5, 4, 9};
    int k = 2;
    cout << "Remove Stones to Minimize the Total : " << s.minStoneSum(piles, k) << endl;
    return 0;
}