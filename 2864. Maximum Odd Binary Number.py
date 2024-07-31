class Solution(object):
    def maximumOddBinaryNumber(self, s):
        a=0
        b=0
        #calculating no of zeros and 1s
        for i in range(len(s)):
            if(s[i]=="1"):
                a=a+1
        b=len(s)-a
        i=0
        return "1"*(a-1) +"0"*b +"1"
        