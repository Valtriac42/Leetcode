class Solution(object):
    def intersection(self, nums1, nums2):
        ln1 = len(nums1)
        ln2 = len(nums2)
        A = []
        flag = 0
        flag2 = 0
        one = 0
        for i in range(ln1):
            j = 0
            for j in range(ln2):
                if(nums1[i] == nums2[j]):
                    flag = 1
                    break
            if(flag == 1):
                flag = 0
                z = 0
                if(one == 0):
                    A.append(nums1[i])
                    one = 1
                else:
                    flag2 = 0
                    for z in range(len(A)):
                        if(nums1[i] == A[z]):
                            flag2 = 1
                            break
                    if(flag2 == 0):
                        A.append(nums1[i])
        return A

# Taking inputs from the user
nums1 = list(map(int, input("Enter the first list of numbers separated by space: ").split()))
nums2 = list(map(int, input("Enter the second list of numbers separated by space: ").split()))

sol = Solution()
print("Intersection of the two lists:", sol.intersection(nums1, nums2))
