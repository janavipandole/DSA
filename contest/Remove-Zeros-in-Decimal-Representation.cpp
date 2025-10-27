#include <iostream>
using namespace std;
class Solution
{
public:
    long long removeZeros(long long n)
    {
        long long ans = 0;
        string word;
        string num = to_string(n);

        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] != '0') word += num[i];
        }

        ans = stoll(word);
        return ans;
    }
};
int main()
{
    Solution s;
    long long n = 2249987923;
    cout << "Remove Zeros in Decimal Representation : " << s.removeZeros(n) << endl;
    return 0;
}