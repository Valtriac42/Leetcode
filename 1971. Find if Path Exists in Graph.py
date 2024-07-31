from typing import List
from collections import defaultdict

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        l = defaultdict(list)

        for _ in range(n-1):
            edge = list(map(int, input("Enter edge (format: u v): ").split()))
            edges.append(edge)

        for i, j in edges:
            l[i].append(j)
            l[j].append(i)

        s = set()

        def dfs(node):
            if node == destination:
                return True
            s.add(node)
            for j in l[node]:
                if j not in s and dfs(j):
                    return True
            return False
        
        return dfs(source)

solution = Solution()
n = int(input("Enter number of nodes: "))
edges = []
source = int(input("Enter source node: "))
destination = int(input("Enter destination node: "))
print("Is there a valid path?", solution.validPath(n, edges, source, destination))
