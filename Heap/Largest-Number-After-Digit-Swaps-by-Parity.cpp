#include <iostream>
using namespace std;
class Solution
{
public:
    int largestInteger(int num)
    {
        int dummy = num;

        string s = to_string(dummy);

        priority_queue<int> even, odd;

        while (num > 0)
        {
            int digit = num % 10;

            if (digit % 2 == 0)
                even.push(digit);
            else
                odd.push(digit);

            num /= 10;
        }
        int ans = 0;

        for (auto ch : s)
        {
            int d = ch - '0';
            if (d % 2 == 0)
            {
                ans = ans * 10 + even.top();
                even.pop();
            }
            else
            {
                ans = ans * 10 + odd.top();
                odd.pop();
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;
    int num = 1234;
    cout << "Largest Number After Digit Swaps by Parity : " << s.largestInteger(num) << endl;
    return 0;
}