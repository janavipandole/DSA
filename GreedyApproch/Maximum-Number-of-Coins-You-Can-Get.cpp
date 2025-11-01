#include <iostream>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.rbegin(), piles.rend());
        int cnt = piles.size() / 3;
        int sum = 0;
        int i = 1;
        while(cnt > 0){
            sum += piles[i];
            i += 2;
            cnt--;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> piles = {9, 8, 7, 6, 1, 2, 3, 4, 5};
    cout << "Maximum Number of Coins You Can Get : " << s.maxCoins(piles) << endl;
    return 0;
}