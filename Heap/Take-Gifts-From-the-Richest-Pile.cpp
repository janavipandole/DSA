#include <iostream>
using namespace std;
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> maxHeap;
        for (int i = 0; i < gifts.size(); i++)
        {
            maxHeap.push(gifts[i]);
        }

        for (int i = 0; i < k; i++)
        {
            int num = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(num));
        }

        long long ans = 0;
        while (maxHeap.size() > 0)
        {
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    cout << "Take Gifts From the Richest Pile : " << s.pickGifts(gifts, k) << endl;
    return 0;
}