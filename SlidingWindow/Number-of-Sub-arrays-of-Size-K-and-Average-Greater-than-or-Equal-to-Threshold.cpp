#include <iostream>
using namespace std;
class Solution
{
public:
    int numOfSubarrays_Brute(vector<int> &nums, int k, int threshold)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0, sum = 0, avg = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                cnt++;
                if (cnt < k) continue;

                if (cnt == k)
                {
                    avg = sum / k;
                    if (avg >= threshold) count++;
                }
                break;
            }
        }
        return count;
    }

    int numOfSubarrays_Better(vector<int> &nums, int k, int threshold)
    {
        int ans = 0, st = 0, end = 0, sum = 0, count = 0, n = nums.size();
        double avg = 0;
        while (end < n)
        {
            sum += nums[end];
            count++;

            while (count > k)
            {
                sum -= nums[st];
                count--;
                st++;
            }

            if (count == k)
            {
                avg = sum / k;
                if (avg >= threshold) ans++;
            }
            end++;
        }
        return ans;
    }

    int numOfSubarrays_Optimal(vector<int> &nums, int k, int threshold)
    {
        int ans = 0, st = 0, end = 0, sum = 0, count = 0, n = nums.size();
        double avg = 0;
        while (end < n)
        {
            sum += nums[end];
            count++;

            if (count > k)
            {
                sum -= nums[st];
                count--;
                st++;
            }

            if (count == k)
            {
                avg = sum / k;
                if (avg >= threshold) ans++;
            }
            end++;
        }
        return ans;
    }

    int numOfSubarrays_Most_Optimal(vector<int> &arr, int k, int t)
    {
         int n = arr.size();
        
        int sum = 0; int count = 0;
        for( int i = 0; i < k; i++){
             sum += arr[i];
            }
        if( sum / k >= t )count++;

        for( int i = k; i < n; i++){
            sum += arr[i] - arr[i - k];
            
            if( sum / k >= t )count++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {11,13,17,23,29,31,7,5,2,3};
    int k = 3, T = 5;
    cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold : " << s.numOfSubarrays_Brute(nums, k, T) << endl;
    cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold : " << s.numOfSubarrays_Better(nums, k, T) << endl;
    cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold : " << s.numOfSubarrays_Optimal(nums, k, T) << endl;
    cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold : " << s.numOfSubarrays_Most_Optimal(nums, k, T) << endl;
    return 0;
}