#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        if(deck.size() <= 1) return false;
        
        unordered_map<int, int> hash;
        for (auto num : deck)
        {
            hash[num]++;
        }
        int count = 0;
        for (auto &[num, cnt] : hash)
        {
            if (count == 0)
            {
                count = cnt;
            }
            if (count != cnt)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    cout << "X of a Kind in a Deck of Cards : " << s.hasGroupsSizeX(deck) << endl;
    return 0;
}