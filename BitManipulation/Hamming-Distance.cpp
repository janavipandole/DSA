#include <iostream>
using namespace std;
int hammingDistance(int x, int y)
{
    int XOR = x ^ y;
    int count = __builtin_popcount(XOR);
    return count;
}
int main()
{
    int x = 1, y = 4;
    cout<<"Hamming Distance : "<<hammingDistance(x,y)<<endl;
    return 0;
}