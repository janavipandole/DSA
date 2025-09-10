#include <iostream>
using namespace std;
int getBit(int num, int i)
{
    return (num & (1 << i)) ? 1 : 0;
}
int setBit(int num, int i)
{
    return (num | (1 << i));
}
int clearBit(int num, int i)
{
    return num & ~(1 << i);
}
void bitManipulation(int num, int i)
{
    i = i - 1;
    cout << getBit(num, i) << " " << setBit(num, i) << " " << clearBit(num, i) << endl;
}
int main()
{
    // 0000011110110100010000111100
    int num = 70, i = 3;
    cout << "Bit Manipulation : " << endl;
    bitManipulation(num, i);
    return 0;
}