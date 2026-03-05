#include <iostream>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();
        int pattern1 = 0; // "010101..."
        int pattern2 = 0; // "101010..."

        for (int i = 0; i < n; i++)
        {

            // pattern "0101..."
            if (i % 2 == 0)
            {
                if (s[i] != '0') pattern1++;
            }
            else
            {
                if (s[i] != '1') pattern1++;
            }

            // pattern "1010..."
            if (i % 2 == 0)
            {
                if (s[i] != '1') pattern2++;
            }
            else
            {
                if (s[i] != '0') pattern2++;
            }
        }

        return min(pattern1, pattern2);
    }
};
int main()
{
    Solution s;
    string str = "0100";
    cout << "Minimum Changes To Make Alternating Binary String : "<<s.minOperations(str) << endl;
    return 0;
}