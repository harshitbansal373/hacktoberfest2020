# Using a Python dictionary to act as an adjacency list
graph = {
    'A' : ['B','C'],
    'B' : ['D', 'E'],
    'C' : ['F'],
    'D' : [],
    'E' : ['F'],
    'F' : []
}

visited = set() # Set to keep track of visited nodes.

def dfs(visited, graph, node):
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
dfs(visited, graph, 'A')
#Implemented using an Adjacency Graph Concept.
class graph:
    def __init__(self):
        self.vertices=int(input("Enter number of Vertices: "))
        self.adj=[]
        for i in range(self.vertices):
            temp=[0 for j in range(self.vertices)]
            self.adj.append(temp)

    def add_edge(self):
        Vpair=list(map(int,input("Enter the Vertices(Space Seperated): ").split()))
        self.adj[Vpair[0]][Vpair[1]]=1
        self.adj[Vpair[1]][Vpair[0]]=1
    def print_edges(self):
        for i in range(self.vertices):
            for j in range(self.vertices):
                print(self.adj[i][j],end=" ")
            print(self.adj[i][j])

    def DFS(self,i,visited):
    	visited[i]=True
    	self.output.append(i)
    	for j in range(self.vertices):
    		if(self.adj[i][j]==1 and visited[j]==False):
    			self.DFS(j,visited)

    def DFSInit(self):
    	visited=[False  for  sv in range(self.vertices)]
    	stack=[0 for  sv in range(self.vertices)]
    	self.output=[]
    	top=-1
    	self.DFS(0,visited)


    	print("The DFS Traversal of the Graph is: ",end=" ")
    	for i in self.output:
    		print(i,end=" ")


G=graph()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.add_edge()
G.print_edges()
G.DFSInit()
print("All OK") 