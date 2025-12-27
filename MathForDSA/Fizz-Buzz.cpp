#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        while (n > 0)
        {
            if (n % 3 == 0 && n % 5 == 0)
            {
                ans[n - 1] = "FizzBuzz";
            }
            else if (n % 3 == 0)
            {
                ans[n - 1] = "Fizz";
            }
            else if (n % 3 == 0)
            {
                ans[n - 1] = "Buzz";
            }
            else
            {
                ans[n - 1] = to_string(n);
            }
            n--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 15;
    cout << "Fizz Buzz : " << endl;
    vector<string> ans = s.fizzBuzz(n);
    for (auto str : ans)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}