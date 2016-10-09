#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> graph[112345];
int n, m, a, b, c,x, visited[112345],parent[112345],dis[112345];
 
int main () {
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	parent[0] = 0;
	dis[0] = 0;
	while(!q.empty()) {
		c = q.front();
		q.pop();
		if(!visited[c]) {
			visited[c] = 1;
			for(int i = 0; i < graph[c].size(); i += 1)
			{
				
			 parent[graph[c][i]]= c;		//so we have parent of every vertex
			 dis[graph[c][i]] = dis[c] + 1;		//we also have shortest path to all vertex from 0
			 q.push(graph[c][i]);
			}
		}
	}
	
}
