#include <iostream>
using namespace std;
bool isPrefixAndSuffix(string str1, string str2)
{
    if (str2.size() < str1.size())
    {
        return false;
    }
    int i = 0;
    while (i < str1.size() && i < str2.size())
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    i = str1.size() - 1;
    int j = str2.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (str1[i] != str2[j])
        {
            return false;
        }
        i--;
        j--;
    }
    return true;
}
int countPrefixSuffixPairs(vector<string> &words)
{
    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (isPrefixAndSuffix(words[i], words[j]))
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<string> words = {"pa", "papa", "ma", "mama"};
    cout << "Count Prefix and Suffix Pairs I : " << countPrefixSuffixPairs(words) << endl;

    return 0;
}