#include <iostream>
using namespace std;
class Solution
{
public:
    bool isOdd(int num)
    {
        return num % 2 != 0;
    }
    string largestOddNumber_1(string num)
    {
        string word = "", ans = "";

        for (int i = 0; i < num.size(); i++)
        {
            word += num[i];
            if (isOdd(stoll(word)))
            {
                ans = word;
            }
        }
        return ans;
    }

    string largestOddNumber_2(string num)
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};
int main()
{
    Solution s;
    string num = "239537672423884969653287101";
    string num1 = "35";
    cout << "Largest Odd Number in String : " << s.largestOddNumber_1(num1) << endl;
    cout << "Largest Odd Number in String : " << s.largestOddNumber_2(num) << endl;

    return 0;
}