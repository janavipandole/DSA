#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] > b[1];
             });

        int totalUnits = 0;

        for (auto &box : boxTypes)
        {
            if (truckSize == 0)
                break;

            int boxes = min(box[0], truckSize);
            totalUnits += boxes * box[1];
            truckSize -= boxes;
        }

        return totalUnits;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = truckSize = 4;
    cout << "Maximum Units on a Truck : " << s.maximumUnits(boxTypes, truckSize) << endl;
    return 0;
}
