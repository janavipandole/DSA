#include <iostream>
using namespace std;
class Solution
{
public:
    void invert(string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
    }
    char findKthBit(int n, int k)
    {
        if (k == 1 || n == 1)
        {
            return '0';
        }

        string prev = "0";
        string current;
        for (int i = 2; i <= n; i++)
        {
            current = prev + "1";
            invert(prev);
            reverse(prev.begin(), prev.end());
            current += prev;
            prev = current;
        }
        return current[k - 1];
    }
};
int main()
{
    Solution s;
    int n = 4, k = 11;
    cout << "Find Kth Bit in Nth Binary String : " << s.findKthBit(n, k) << endl;
    return 0;
}