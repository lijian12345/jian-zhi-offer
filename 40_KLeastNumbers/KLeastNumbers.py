import heapq


class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        if not tinput or k <= 0 or k > len(tinput):
            return []
        if k == len(tinput):
            return tinput
        low = 0
        high = len(tinput) - 1
        index = self.Partition(tinput, low, high)
        while index != k - 1:
            if index > k - 1:
                high = index - 1
            else:
                low = index + 1
            index = self.Partition(tinput, low, high)
        return tinput[:k]

    def Partition(self, tinput, low, high):
        if low < high:
            pivot = tinput[low]
            while low < high:
                while low < high and tinput[high] >= pivot:
                    high -= 1
                tinput[low] = tinput[high]
                while low < high and tinput[low] <= pivot:
                    low += 1
                tinput[high] = tinput[low]
            tinput[low] = pivot
        return low


class Solution1:
    def GetLeastNumbers_Solution(self, tinput, k):
        if not tinput or k <= 0 or k > len(tinput):
            return []

        heapq.heapify(tinput)
        return [heapq.heappop(tinput) for _ in range(k)]


L = [4, 5, 1, 6, 2, 7, 3, 8]
s = Solution1()
LL = s.GetLeastNumbers_Solution(L, 4)
print(LL)
