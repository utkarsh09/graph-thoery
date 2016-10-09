#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
 
#define MAX_NODES (int)1e5
 
using namespace std;
 
vector<vector<int> > graph (MAX_NODES);
bool visited[MAX_NODES];
 
 
bool dfs (int root,int target)
{
	// We will Use A Stack To DO The DFS
	stack<int> s;
 
	// Push The Root Node And Start The Computation
	s.push (root);
 
	while (!s.empty())
	{
		int current = s.top (); // Represents The Current Node That We Are Looking at.
		s.pop ();
 
		visited[current] = true;
 
		for (vector<int>::iterator it = graph[current].begin();it != graph[current].end();++it )
		{
 
			if (*it == target)
				return true; // We Have Found The Target And We Are Done
			else
			{
				if (visited[*it] == false)
					s.push (*it);
			}
 
		}
	}
 
	return false; // If Control Reaches Here It Means That We Couldn't Find The Node We Were Looking For
 
}
 
int main ()
{
	int N,M; // Number Of Nodes And Edges
	int target;
	int root;
 
	scanf ("%d",&N);
	scanf ("%d",&M);
 
	for (int i=0;i<N;i++)
		visited[i] = false;
 
	for (int i=0;i<M;i++)
	{
		int from,to; // Used To Represent An Edge
 
		scanf ("%d",&from);
		scanf ("%d",&to);
 
		graph[from].push_back (to); // Inserting To Adjecency List
		graph[to].push_back (from); // Insert Both Ways Because It Is Undirected Graph
 
	}
 
	// For Doing a DFS You Need A Root And A Target
	// Take That As Input
 
	scanf ("%d",&root);
	scanf ("%d",&target);
 
 
	// Use The Root As The Start Node
	if (dfs(root,target))
		printf ("Got The Node\n");
	else
		printf ("Din't Find The Node\n");
 
 
	return  0;
}