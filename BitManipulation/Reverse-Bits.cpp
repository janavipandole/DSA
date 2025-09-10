#include <iostream>
using namespace std;

int reverseBits(int n)
{
    int result = 0;
    for (int i = 0; i < 32; ++i)
    {
        result <<= 1;      
        result |= (n & 1);
        n >>= 1;          
    }
    return result;
}
int main()
{
    int n = 43261596;
    cout << "Reverse Bits : " << reverseBits(n) << endl;
    return 0;
}