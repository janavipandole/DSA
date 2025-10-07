#include <iostream>
using namespace std;

class Solution
{
public:
    int convert(string s)
    {
        int n = s.size();
        if (n % 2 != 0) return 0;

        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n / 2; i++) sum1 += s[i] - '0';
        for (int i = n / 2; i < n; i++) sum2 += s[i] - '0';
        return sum1 == sum2 ? 1 : 0;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;
        while (low <= high)
        {
            cnt += convert(to_string(low));
            low++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int low = 1200, high = 1230;
    cout << "Count Symmetric Integers : " << s.countSymmetricIntegers(low, high) << endl;
    return 0;
}