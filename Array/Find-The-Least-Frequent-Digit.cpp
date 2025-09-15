#include <iostream>
#include <unordered_map>
using namespace std;
int getLeastFrequentDigit(int n)
{
    unordered_map<int, int> m;

    while (n > 0)
    {
        int digit = n % 10;
        m[digit] += 1;
        n /= 10;
    }
    int LeastFrequentDigit = INT_MAX;
    int Freq = INT_MAX;

    for (auto val : m)
    {
        if (val.second < Freq)
        {
            Freq = val.second;
            LeastFrequentDigit = val.first;
        }
        if (val.second == Freq && LeastFrequentDigit > val.first)
        {
            Freq = val.second;
            LeastFrequentDigit = val.first;
        }
    }
    return LeastFrequentDigit;
}
int main()
{
    int n = 723344511;
    cout << "Find The Least Frequent Digit : " << getLeastFrequentDigit(n) << endl;
    return 0;
}