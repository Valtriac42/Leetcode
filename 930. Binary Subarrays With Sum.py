from typing import List
from collections import Counter

class Solution:
    def numSubarraysWithSum(self, a: List[int], g: int) -> int:
        return (z:=Counter([0]),s:=0) and sum((s:=s+v,z[s-g],setitem(z,s,z[s]+1))[1] for v in a)
