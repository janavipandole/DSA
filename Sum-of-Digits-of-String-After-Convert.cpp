#include <iostream>
using namespace std;
int getLucky(string s, int k)
{
    string sum;
    unordered_map<char, int> mpp;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        mpp[ch] = ch - 'a' + 1;
    }
    
    return 0;
}
int main()
{
    string s = "leetcode";
    int k = 1;
    cout << "Sum of Digits of String After Convert : " << getLucky(s, k) << endl;
    return 0;
}