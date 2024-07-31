class Solution(object):
    def maxFrequencyElements(self):
        nums = list(map(int, input("Enter the list of numbers separated by space: ").split()))
        nums.sort()
        a = 0
        b = 0
        val = 0
        high = 1
        print(nums)
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                a += 1
            elif a != 0:
                if b == a:
                    high += 1
                    val = a
                elif b < a:
                    b = a
                    val = a
                    high = 1
                a = 0
            print(a)
        if a != 0:
            if b == a:
                high += 1
                val = a
                a = 0
            elif b < a:
                b = a
                val = a
                high = 1
                a = 0
            
        a = high * (val + 1)
        if a == 1:
            return len(nums)
        print("high")
        print(high)
        print("val")
        print(val)
        return a

solution = Solution()
print("Maximum Frequency of Elements:", solution.maxFrequencyElements())
