#include <iostream>
using namespace std;

int printOneSubSeq(vector<int> &nums, int k, int index)
{

    if (index == nums.size())
    {
        if (k == 0)
        {
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    cnt += printOneSubSeq(nums, k - nums[index], index + 1);

    cnt += printOneSubSeq(nums, k, index + 1);

    return cnt;
}

int main()
{
    vector<int> nums = {1, 2, 1,0};
    int k = 3;

    cout << "Print One Sub Seq : " << printOneSubSeq(nums, k, 0)<<endl;
    return 0;
}