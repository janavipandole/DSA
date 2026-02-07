#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int index = -1;
        string ans;
        
        for (int i = num.size()-1; i >= 0; i--)
        {
            if (num[i] != '0')
            {
                index = i;
                break;
            }
        }
        for (int i = 0; i <= index; i++)
        {
            ans += num[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string num = "51230100";
    cout << "Remove Trailing Zeros From a String : " << s.removeTrailingZeros(num) << endl;
    return 0;
}