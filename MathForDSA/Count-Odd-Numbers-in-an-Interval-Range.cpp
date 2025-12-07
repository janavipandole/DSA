#include <iostream>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;

        if (low % 2 == 0)
            low++;
        for (int num = low; num <= high;)
        {
            if (num % 2 != 0)
            {
                count++;
            }
            num += 2;
        }

        return count;
    }
};

int main()
{
    Solution s;
    int low = 8, high = 10;
    cout << "Count Odd Numbers in an Interval Range : " << s.countOdds(low, high) << endl;
    return 0;
}