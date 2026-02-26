#include <iostream>
using namespace std;
class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--)
        {
            int bit = s[i] - '0';

            if ((bit + carry) % 2 == 0)
            {
                steps += 1; // even → divide
            }
            else
            {
                steps += 2; // odd → add + divide
                carry = 1;
            }
        }

        return steps + carry;
    }
};
int main()
{
    Solution s;
    string str = "1101";
    cout << "Number of Steps to Reduce a Number in Binary Representation to One : " << s.numSteps(str) << endl;
    return 0;
};