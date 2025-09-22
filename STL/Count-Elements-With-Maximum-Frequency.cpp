#include <iostream>
#include <map>
using namespace std;
int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int maxFreq = 0, maxFreqElem = 0;
    for (auto num : nums)
    {
        mpp[num]++;
        maxFreq = max(maxFreq, mpp[num]);
    }

    for (auto &[key, value] : mpp) if (value == maxFreq) maxFreqElem += maxFreq;

    return maxFreqElem;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Count Elements With Maximum Frequency : " << maxFrequencyElements(nums) << endl;
    return 0;
}