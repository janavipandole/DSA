#include <iostream>
using namespace std;
vector<int> evenOddBit(int n)
{
    int even = 0;
    int odd = 0;
    int index = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            if (index % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        index++;
        n /= 2;
    }
    return {even, odd};
}
int main()
{
    cout << "Number of Even and Odd Bits : " << endl;
    vector<int> nums = evenOddBit(50);
    cout<<nums[0]<<" "<<nums[1]<<endl;
    return 0;
}