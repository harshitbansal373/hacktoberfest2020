//DFS Implementation using the article on GFG
#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V,W;
	list<int> *adj;
	
	void DFS(int v,bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v,string w);
		void dfs(int s);
	
};
Graph::Graph(int V)
{
	this->V=V;
	adj = new list<string>[V];
}
void Graph::addEdge(int v,string w)
{
	adj[v].push_back(w);
}
void Graph::DFS(int v,bool visited[])
{
	visited[v] = true;
	cout<<v<<" ";
	
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
			DFS(*i,visited);
	}
}
void Graph::dfs(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	
	DFS(s,visited);
	
}
int main()
{
	int h,w;
	cin>>h>>w;
	string s;
	Graph g(h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			{
				cin>>s;
				g.addEdge(i,s);
			}
	}
  	cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.dfs(0);
}
