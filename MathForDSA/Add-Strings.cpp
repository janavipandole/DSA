#include <iostream>
using namespace std;
string addStrings(string num1, string num2)
{
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string ans = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += num1[i--] - '0';
        }
        if (j >= 0)
        {
            sum += num2[j--] - '0';
        }
        ans.push_back((sum%10)+'0');
        carry=sum/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string num1 = "11", num2 = "123";
    cout << "Add Strings : " << addStrings(num1, num2) << endl;
    return 0;
}