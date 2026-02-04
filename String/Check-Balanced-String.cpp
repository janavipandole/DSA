#include <iostream>
using namespace std;

class Solution
{
public:
    bool isBalanced(string num)
    {
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (i % 2 == 0)
            {
                evenSum += num[i] - '0';
            }
            else
            {
                oddSum += num[i] - '0';
            }
        }
        cout << evenSum << " " << oddSum << endl;
        return evenSum == oddSum;
    }
};
int main()
{
    Solution s;
    string num = "24123";
    cout << "Check Balanced String : " << s.isBalanced(num) << endl;
    return 0;
}