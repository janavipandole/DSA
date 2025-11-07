#include <iostream>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        if (costs[0] > coins)
            return 0;
        if (coins == 0)
            return 0;

        int max_ice_cream_bars = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++)
        {
            if (coins <= 0 || costs[i] > coins)
                break;
            coins -= costs[i];
            max_ice_cream_bars++;
        }

        return max_ice_cream_bars;
    }
};

int main()
{
    Solution s;
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    cout << "Maximum Ice Cream Bars : " << s.maxIceCream(costs, coins) << endl;
    return 0;
}