# use minHeap to keep the k largest elements so far, with
# the kth largest element at the top of the heap.
from heapq import heapify, heappop


class Solution(object):
    def kthLargestNumber(self, nums, k):
        """
        :type nums: List[str]
        :type k: int
        :rtype: str
        """

        maxHeap = [-int(x) for x in nums]
        heapify(maxHeap)

        while k > 1:
            heappop(maxHeap)
            k -= 1

        return str(-maxHeap[0])
