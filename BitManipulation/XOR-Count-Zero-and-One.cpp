#include <iostream>
using namespace std;
int find_xor(int n)
{
    int setBit = 0;
    int unSetBit = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            setBit++;
        }
        else
        {
            unSetBit++;
        }
        n /= 2;
    }
    return setBit ^ unSetBit;
}
int main()
{
    cout<<"XOR Count Zero and One : "<<find_xor(7)<<endl;
    return 0;
}