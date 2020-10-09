# -*- coding: utf-8 -*-
"""
Created on Thu Jun 18 21:18:21 2020

@author: Hp
"""

import sys
from heapq import heappop,heappush

class Edge:
    
    def __init__(self, weight, startVertex, endVertex):
        self.weight = weight
        self.startVertex = startVertex
        self.endVertex = endVertex

    # Dijkstra is used for single source, if source is changed then it
    # has to be calculated again. It can't handle -ve edge weights.
    # O(V+E)
    # Bellman ford can be used for -ve edge weights and for detecting -ve cycles.
    

class Node:
    
    def __init__(self, name):
        
        self.name = name
        self.predecessor = None
        self.minDistance = sys.maxsize
        self.adjList = []
        self.visited = False
        
    """def __cmp__(self, otherVertex):
        
        return self.cmp(self.minDistance,otherVertex.minDistance)
    """
    def __lt__(self,other):
        
        selfPri = self.minDistance
        otherPri = other.minDistance
        return selfPri < otherPri
    
    
    
class dijkstra:
    
    def cal_short_path(self, startVertex):
        
        q = []
        heappush(q, startVertex)
        startVertex.minDistance = 0
        
        while q:
            
            actualVertex = heappop(q)
            
            for edge in actualVertex.adjList:
                
                u = edge.startVertex
                v = edge.endVertex
                
                if v.minDistance > u.minDistance + edge.weight:
                    v.minDistance = u.minDistance + edge.weight
                    v.predecessor = u
                    heappush(q, v)
                    
    def print_short_path(self, targetVertex):
            print(targetVertex.minDistance)

            while targetVertex is not None:
                print(targetVertex.name)
                targetVertex = targetVertex.predecessor
                
n1 = Node("a")
n2 = Node("b")
n3 = Node("c")
n4 = Node("d")
n5 = Node("e")
n6 = Node("f")

e1 = Edge(5,n1,n2)
e2 = Edge(8,n1,n4)
e3 = Edge(20,n2,n5)
e4 = Edge(15,n3,n5)
e5 = Edge(12,n3,n6)
e6 = Edge(4,n4,n2)
e7 = Edge(9,n5,n4)
e8 = Edge(7,n6,n6)

n1.adjList.append(e1)
n1.adjList.append(e2)
n1.adjList.append(e3)
n2.adjList.append(e4)
n2.adjList.append(e5)
n3.adjList.append(e6)

algo = dijkstra()
algo.cal_short_path(n1)
algo.print_short_path(n6)



            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
