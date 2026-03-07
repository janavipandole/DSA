#include <iostream>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        s = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = n;

        for (int i = 0; i < s.size(); i++)
        {
            char expected1 = (i % 2) ? '1' : '0'; // pattern 010101
            char expected2 = (i % 2) ? '0' : '1'; // pattern 101010

            if (s[i] != expected1) diff1++;
            if (s[i] != expected2) diff2++;

            if (i > n - 1)
            {
                char prev1 = ((i - n) % 2) ? '1' : '0';
                char prev2 = ((i - n) % 2) ? '0' : '1';

                if (s[i - n] != prev1) diff1--;
                if (s[i - n] != prev2) diff2--;
            }
            if (i >= n - 1)
            {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string str = "010";
    cout << "Minimum Number of Flips to Make the Binary String Alternating : " << s.minFlips(str) << endl;
    return 0;
}