class Solution(object):
    def plusOne(self, digits):
        digits = list(map(int, input("Enter the digits separated by spaces: ").split()))
        i = len(digits) - 1
        carry = 0
        while(True):
            digits[i] = digits[i] + 1
            if(digits[i] >= 10):
                digits[i] = digits[i] % 10
                carry = 1
                i = i - 1
            else:
                carry = 0
            if(carry != 0 and i == -1):
                digits.insert(0, 1)
                break
            if(carry == 0):
                break
        return digits
