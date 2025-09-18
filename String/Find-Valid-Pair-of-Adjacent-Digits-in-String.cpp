#include <iostream>
using namespace std;

string findValidPair(string s)
{
     vector<int> freq(10, 0);
    string ans;

    // Count frequency of each digit
    for (char ch : s) {
        freq[ch - '0']++;
    }

    // Find digits where frequency == digit value
    for (char ch : s) {
        int digit = ch - '0';
        if (freq[digit] == digit) {
            if (ans.empty() || ans.back() != ch) {
                ans += ch;
                if (ans.size() == 2) break;
            }
        }
    }

    return ans.size() == 2 ? ans : "";
}
int main()
{
    string s = "1522";
    cout << "Find Valid Pair of Adjacent Digits in String : " << findValidPair(s) << endl;
    return 0;
}