#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        // Reverse traversal like manual multiplication
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert to string, skipping leading zeros
        string ans = "";
        for (int num : result)
        {
            if (!(ans.empty() && num == 0)) ans.push_back(num + '0');
        }

        return ans.empty() ? "0" : ans;
    }
};

int main()
{
    Solution s;
    string num1 = "2", num2 = "3";
    cout << "Multiply Strings : " << s.multiply(num1, num2) << endl;
    return 0;
}