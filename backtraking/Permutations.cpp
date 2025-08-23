#include <iostream>
using namespace std;

// Brute force approch
void getAllPermutationsBrute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &result, vector<int> &freq)
{
    if (ds.size() == nums.size())
    {
        result.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] == 0)
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            getAllPermutationsBrute(nums, ds, result, freq);

            ds.pop_back();
            freq[i] = 0;
        }
    }
}

// Optimal Approche
void getAllPermutationsOptimal(vector<int> &nums, vector<vector<int>> &result, int index)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        getAllPermutationsOptimal(nums, result, index + 1);
        swap(nums[i], nums[index]);
    }
}

int main()
{

    vector<int> nums{1, 2, 3};

    // Optimal Approche
    vector<vector<int>> answer;
    getAllPermutationsOptimal(nums, answer, 0);

    cout << "Optimal Approche : " << endl;
    for (auto res : answer)
    {
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Brute force approche
    vector<int> ds;
    vector<vector<int>> result;
    vector<int> freq(nums.size(), 0);
    getAllPermutationsBrute(nums, ds, result, freq);

    cout << "Brute force approche : " << endl;
    for (auto res : result)
    {
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}