#include <iostream>
#include <unordered_map>
using namespace std;
void print(unordered_map<int, int> &mpp)
{
    cout << "Size : " << mpp.size() << endl;
    for (auto &[key, value] : mpp)
        cout << key << " " << value << endl;
}
int main()
{
    vector<int> nums = {4, 5, 6, 9, 2, 3, 4, 5, 4};
    unordered_map<int, int> mpp;
    for (auto num : nums)
    {
        mpp[num]++;
    }
    print(mpp);
    mpp.clear();
    print(mpp);
    return 0;
}