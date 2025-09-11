#include <iostream>
using namespace std;
int bitwiseComplement(int num)
{
    if (num == 0)
    {
        return 1;
    }
    int ans = 0;
    int pow = 1;
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            ans += pow;
        }
        pow *= 2;
        num /= 2;
    }
    return ans;
}
int main()
{
    cout<<"Complement of Base 10 Integer : "<<bitwiseComplement(10)<<endl;
    return 0;
}