#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumRecolors_Brute(string blocks, int k)
    {
        int minCnt = INT_MAX;
        for (int i = 0; i < blocks.size(); i++)
        {
            int cntW = 0, cntK = 0;
            for (int j = i; j < blocks.size(); j++)
            {
                cntK++;
                if (cntK > k)
                    break;
                if (blocks[j] == 'W')
                    cntW++;

                if (cntK == k)
                {
                    minCnt = min(minCnt, cntW);
                }
            }
        }
        return minCnt;
    }

    int minimumRecolors_Better(string blocks, int k)
    {
        int minCnt = INT_MAX, cntW = 0, cntK = 0, st = 0, end = 0;
        while (end < blocks.size())
        {
            cntK++;

            while(cntK > k){
                cntK--;
                if (blocks[st] == 'W') cntW--;
                st++;
            }

            if (blocks[end] == 'W') cntW++;

            if (cntK == k) minCnt = min(minCnt, cntW);
            end++;
        }
        return minCnt;
    }

     int minimumRecolors_Optimal(string blocks, int k)
    {
        int minCnt = INT_MAX, cntW = 0, cntK = 0, st = 0, end = 0;
        while (end < blocks.size())
        {
            cntK++;

            if(cntK > k){
                cntK--;
                if (blocks[st] == 'W') cntW--;
                st++;
            }

            if (blocks[end] == 'W') cntW++;

            if (cntK == k) minCnt = min(minCnt, cntW);
            end++;
        }
        return minCnt;
    }

     int minimumRecolors_Most_Optimal(string blocks, int k)
    {
        int balance = 0;
        for (int i = 0; i < k; ++i) {
            balance += blocks[i] == 'B' ? 1 : 0;
        }

        int bestRes = k - balance;
        for (int i = k; i < blocks.size(); ++i) {
            balance += blocks[i] == 'B' ? 1 : 0;
            balance -= blocks[i - k] == 'B' ? 1 : 0;
            int currRes = k - balance;
            bestRes = min(bestRes, currRes);
        }

        return bestRes;
    }
};
int main()
{
    Solution s;
    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout << "Minimum Recolors to Get K Consecutive Black Blocks : " << s.minimumRecolors_Brute(blocks, k) << endl;
    cout << "Minimum Recolors to Get K Consecutive Black Blocks : " << s.minimumRecolors_Better(blocks, k) << endl;
    cout << "Minimum Recolors to Get K Consecutive Black Blocks : " << s.minimumRecolors_Optimal(blocks, k) << endl;
    cout << "Minimum Recolors to Get K Consecutive Black Blocks : " << s.minimumRecolors_Most_Optimal(blocks, k) << endl;

    return 0;
}