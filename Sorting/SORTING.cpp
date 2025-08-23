#include <iostream>
#include <vector>
using namespace std;

// selection sort
void selectionSort(vector<int> &nums)
{
    //{1, 2, 9, 5, 4, 6}
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[mini])
            {
                mini = j;
            }
        }
        swap(nums[mini], nums[i]);
    }
}

// Bubble sort
void bubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        bool ifSorted = true;
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                ifSorted = false;
            }
        }
        if (ifSorted)
        {
            break;
        }
    }
}

// Insertion sort
void insertionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i;
        //{6, 5, 4, 3, 2, 1}
        while (j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}
int main()
{
    vector<int> nums = {6, 5, 4, 3, 2, 1};
    insertionSort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}