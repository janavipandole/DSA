#include <iostream>
using namespace std;

class Solution
{
public:
    string reversePrefix(string s, int k)
    {
        int start = 0;
        int end = k - 1;

        while (start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string str = "abcd";
    int k = 2;
    cout << "Reverse String Prefix : " << s.reversePrefix(str, k) << endl;
    return 0;
}