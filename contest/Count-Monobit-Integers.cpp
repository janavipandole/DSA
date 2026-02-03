
#include <iostream>
using namespace std;

class Solution
{
public:
    int countMonobit(int n)
    {
        int count = 1; // 0 is always monobit

        long long num = 1; // start from 1 ("1")

        while (num <= n)
        {
            count++;
            num = (num << 1) | 1; // generate 1,3,7,15,...
        }

        return count;
    }
};
int main()
{
    Solution s;
    cout << "Count Monobit Integers : " << s.countMonobit(4) << endl;

    return 0;
}
