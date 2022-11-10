# we must switch the three successive items in order to prevent any ascending or descending patterns.
# get the 3 elements (prev, cur, nxt)
# if these three are in ascending or descending order i,e. prev < cur < nxt or prev > cur > nxt then swap the cur and nxt elements
# repeat this for entire array


class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def swap(l, r):
            nums[l], nums[r] = nums[r], nums[l]

        n = len(nums)
        for i in range(1, n-1):
            prev, cur, nxt = nums[i-1], nums[i], nums[i+1]

            if prev < cur < nxt or prev > cur > nxt:
                swap(i+1, i)
        return nums
