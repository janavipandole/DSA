#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;

        int five = 0, ten = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }
            else{
                if(ten && five){
                    ten--;
                    five--;
                }else if(five >= 3) {
                    five -= 3;
                }else return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> bills = {5,5,5,10,20};
    cout<<"Lemonade Change : "<<s.lemonadeChange(bills)<<endl;
    return 0;
}