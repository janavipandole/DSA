#include <iostream>
using namespace std;
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end());

        if (money < prices[0])
        {
            return money;
        }
        if ((prices[0] + prices[1]) <= money)
        {
            return (money - (prices[0] + prices[1]));
        }
        return money;
    }
};
int main()
{
    Solution s;
    vector<int> prices = {1, 2, 2};
    int money = 3;
    cout << "Buy Two Chocolates : " << s.buyChoco(prices, money) << endl;
    return 0;
}