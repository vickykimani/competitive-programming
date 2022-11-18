// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

class Solution
{
public:
    int maxFrequency(vector<int> &nums, long k)
    {
        int i = 0, j;
        sort(nums.begin(), nums.end());
        for (j = 0; j < nums.size(); ++j)
        {
            k += nums[j];
            if (k < (long)nums[j] * (j - i + 1))
                k -= nums[i++];
        }
        return j - i;
    }
};
