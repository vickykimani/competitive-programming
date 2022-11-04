// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// solve this problem without using the library's sort function.

// element < pivot
// element > pivot

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p = 1;
        int l = 0, r = nums.size() - 1; // setting left and right pointers
        for (int i = 0; i <= r; i++)
        {
            if (nums[i] < p)
            {
                swap(nums[i], nums[l]);
                l++;
            }
            else if (nums[i] > p)
            {
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
        }
    }
};