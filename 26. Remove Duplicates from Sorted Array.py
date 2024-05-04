class Solution:
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
        
        return k

# Example usage
if __name__ == "__main__":
    solution = Solution()
    nums = list(map(int, input("Enter sorted array elements separated by spaces: ").split()))
    result = solution.removeDuplicates(nums)
    print("Length of the array after removing duplicates:", result)
