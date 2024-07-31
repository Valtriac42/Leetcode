class Solution(object):
    def getCommon(self, nums1, nums2):
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if nums1[i] == nums2[j]:
                    return nums1[i]
        return 0

nums1 = input("Enter elements of nums1 separated by space: ").split()
nums2 = input("Enter elements of nums2 separated by space: ").split()

nums1 = [int(num) for num in nums1]
nums2 = [int(num) for num in nums2]

sol = Solution()

common_element = sol.getCommon(nums1, nums2)
print("Common element:", common_element)
