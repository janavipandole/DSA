#include <iostream>
using namespace std;

int countPoints(string rings)
{
    unordered_map<char, string> mpp;
    int result = 0 ;
    for (int i = 0; i < rings.size(); i++)
    {
        if (rings[i] >= '0' && rings[i] <= '9')
        {
            mpp[rings[i]] += rings[i - 1];
        }
    }

    for (auto &[key, value] : mpp)
    {
       bool R = false, B = false, G = false ;
       for(auto val : value){
        if(val == 'R') R = true;
        else if(val == 'B') B = true;
        else G = true;
       }
       if(R && G && B) result++;
    }
    return result;
}
int main()
{
    string rings = "B0B6G0R6R0R6G9";
    cout<<"Rings and Rods : " <<countPoints(rings)<<endl;
    return 0;
}