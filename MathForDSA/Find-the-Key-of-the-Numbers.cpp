#include <iostream>
using namespace std;

class Solution
{
public:
    int generateKey(int num1, int num2, int num3)
    {
        string key = "";
        string s1 = to_string(num1), s2 = to_string(num2), s3 = to_string(num3);

        s1 = string(4 - s1.length(), '0') + s1;
        s2 = string(4 - s2.length(), '0') + s2;
        s3 = string(4 - s3.length(), '0') + s3;

        for (int i = 0; i < s1.size(); i++)
        {
            char minDigit = min({s1[i], s2[i], s3[i]});
            key += minDigit;
        }
        return stoi(key);
    }
};

int main()
{
    Solution s;

    int num1 = 1, num2 = 10, num3 = 1000;
    cout << "Find the Key of the Numbers : " << s.generateKey(num1, num2, num3) << endl;
    return 0;
}