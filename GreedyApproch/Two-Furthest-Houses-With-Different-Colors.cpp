#include <iostream>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
      int n = colors.size();
      if(colors[0] != colors[n-1]) return n-1;

      int maxDis = 0;
      for(int i = 0; i < colors.size(); i++){
        if(colors[i] != colors[n-1]) maxDis = max(maxDis, n - i - 1);
      } 

      for(int i = n-1; i >= 0; i--){
        if(colors[i] != colors[0]) maxDis = max(maxDis, i);

      }
      return maxDis; 
    }
};
int main()
{
    Solution s;
    vector<int> colors = {1,1,1,6,1,1,1};
    cout<<"Two Furthest Houses With Different Colors : "<<s.maxDistance(colors)<<endl;
    return 0;
}