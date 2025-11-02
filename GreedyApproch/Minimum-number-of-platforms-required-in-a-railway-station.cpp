#include <iostream>
using namespace std;
class Solution
{
public:
    int minPlatform_Better(vector<int> &arr, vector<int> &dep)
    {
        if (arr.size() == 0)
        {
            return 0;
        }
        int platform = 1;
        int cnt = 0;
        int n = arr.size();
        vector<pair<int, char>> times;
        for (int i = 0; i < n; i++)
        {
            times.push_back({arr[i], 'A'});
            times.push_back({dep[i], 'D'});
        }
        sort(times.begin(), times.end());

        for (int i = 0; i < times.size(); i++)
        {
            platform = max(platform, cnt);
            if (times[i].second == 'A')
                cnt++;
            else
                cnt--;
        }

        return platform;
    }

    int minPlatform_Optimal(vector<int> &arr, vector<int> &dep)
    {
        if (arr.size() == 0)
        {
            return 0;
        }

        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platform = 1, cnt = 0, i = 0, j = 0;

        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            platform = max(platform, cnt);
        }


        return platform;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2112, 258, 1645, 1608, 2144};
    vector<int> dep = {2307, 1738, 1714, 1907, 2235};
    cout << "Minimum number of platforms required in a railway station : " << s.minPlatform_Better(arr, dep) << endl;
    cout << "Minimum number of platforms required in a railway station : " << s.minPlatform_Optimal(arr, dep) << endl;

    return 0;
}