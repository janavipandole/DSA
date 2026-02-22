#include <iostream>
using namespace std;
class Solution
{
public:
    bool isDigitorialPermutation(int n)
    {
        vector<int> factorial(10, 1);
        for (int i = 2; i < factorial.size(); i++)
        {
            factorial[i] *= factorial[i - 1] * i;
        }

        int newNum = 0;
        int dummy = n;
        while (dummy > 0)
        {
            int digit = dummy % 10;
            newNum += factorial[digit];
            dummy /= 10;
        }
        string s1 = to_string(n);
        string s2 = to_string(newNum);

        if (s1.size() != s2.size())
        {
            return false;
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};
int main()
{
    Solution s;
    int n = 145;
    cout << "Check Digitorial Permutation : " << s.isDigitorialPermutation(n) << endl;
    return 0;
}