#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;

        while (columnNumber){
            columnNumber--;
            int digit = columnNumber % 26;
            ans += char('A' + digit);
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    int columnNumber = 52;
    cout << "Excel Sheet Column Title : " << s.convertToTitle(columnNumber) << endl;
    return 0;
}