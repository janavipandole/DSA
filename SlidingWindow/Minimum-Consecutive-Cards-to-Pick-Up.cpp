#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> mpp;
        int minLen = INT_MAX;

        for (int i = 0; i < cards.size(); i++)
        {
            if(mpp.find(cards[i]) != mpp.end()){
                minLen = min(minLen, i - mpp[cards[i]] + 1);
            }
            mpp[cards[i]] = i;
        }
        if(minLen == INT_MAX) return -1;
        return minLen;
    }
};
int main()
{
    Solution s;
    vector<int> cards = {3, 4, 2, 3, 4, 7};
    cout << "Minimum Consecutive Cards to Pick Up : " << s.minimumCardPickup(cards) << endl;
    return 0;
}