#include <iostream>
using namespace std;

class Solution
{
public:
    string decimalToBinary(int num)
    {
        string binary = "";
        if (num == 0)
            return "0";
        while (num > 0)
        {
            binary = char('0' + num % 2) + binary;
            num /= 2;
        }
        return binary;
    }

    string convertDateToBinary(string date)
    {
        string ans = "";
        int i = 0;
        while (i < date.size())
        {
            string num = "";
            while (i < date.size() && date[i] != '-')
            {
                num += date[i];
                i++;
            }
            if (!ans.empty()) ans += "-";
            ans += decimalToBinary(stoi(num));
            i++; // skip the dash
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string date = "2080-02-29";
    cout << s.convertDateToBinary(date) << endl;
    return 0;
}