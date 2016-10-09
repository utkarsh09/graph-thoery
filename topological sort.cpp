#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
stack<int> s;
int visited[112345],a,b,n,m;


void topological_Sort(int current)
{
	visited[current] = 1;
	vector<int>::iterator it;
	for(it = graph[current].begin();it!=graph[current].end();it++)
	
		if(!visited[*it])
			topological_Sort(*it);
	
	s.push(current);
}

int main()
{
	cout<<"Enter vertices and edges size\n";
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
	}


	for(int i = 0;i<n;i++)
		if(!visited[i])
			topological_Sort(i);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
