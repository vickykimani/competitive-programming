# Given a list of non-negative integers nums, arrange them such that
# they form the largest number and return it.

# Since the result may be very large, so you need to
# return a string instead of an integer.

# a heap is a binary tree where the parent nodes are compared to their children with their values and are arranged accordingly.
# heapq is a data structure that is mainly used to represent a priority queue
# the smallest heap element is popped(min-heap)
# the heapq module of python uses the min heap where the key of the parent is less than or equal to those of its children.

import heapq


class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """

        if not any(nums):
            return "0"

        class dataWrap:  # wrapper class to store strings and order them
            def __init__(self, num):
                self.num = num

            # __lt__ function is the operator overloading function for comparison operators. contains the logic to compare the lengths of strings.
            def __lt__(self, other):
                # maximizing the heap (order largest value to the front.)
                return self.num+other.num > other.num+self.num
        heap = []  # initialising

        # wrap strings and push to heap
        for i in nums:
            heapq.heappush(heap, dataWrap(str(i)))  # push string i into heap
        res = ""
        while heap:
            res += heapq.heappop(heap).num
            # when we pop from our heap, it will remove the smallest value from the heap and return it.
        return res
