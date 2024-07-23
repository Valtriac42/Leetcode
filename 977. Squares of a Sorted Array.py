class Solution(object):
    def sortedSquares(self, nums):
        A=[]
        for i in range(len(nums)):
            nums[i] = nums[i] * nums[i]
            A.append(nums[i])
        
        A.sort()
        return A


if __name__ == "__main__":
    solution = Solution()
    nums = list(map(int, input("Enter space-separated integers: ").split()))
    result = solution.sortedSquares(nums)
    print("Sorted squares:", result)
