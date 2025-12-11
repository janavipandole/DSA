#include <iostream>
using namespace std;
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int total = numBottles; // you drink all initial bottles
        int empty = numBottles;

        while (empty >= numExchange)
        {
            int newBottles = empty / numExchange;
            total += newBottles;                        // drink these bottles
            empty = newBottles + (empty % numExchange); // new empties + leftover empties
        }

        return total;
    }
};
int main()
{
    Solution s;

    int numBottles = 15, numExchange = 4;
    cout << "Water Bottles : " << s.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}