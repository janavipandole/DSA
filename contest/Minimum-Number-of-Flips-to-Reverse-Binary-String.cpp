#include <iostream>
using namespace std;
class Solution
{
public:
    string decimaToBinary(int num)
    {
        int n = num;
        string ans = "";

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int minimumFlips(int n)
    {
        string bits = decimaToBinary(n);
        string revBits = bits;
        reverse(revBits.begin(), revBits.end());

        int count = 0;
        for (int i = 0; i < bits.size(); i++)
        {
            if (bits[i] != revBits[i])
                count++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    cout << "Minimum Number of Flips to Reverse Binary String : " << s.minimumFlips(10) << endl;
    return 0;
}