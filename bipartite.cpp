#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];

int visited[112345],parent[112345],n,m,a,b,color[112345];

bool bipartiteCheck(int source)
{
	for(int i = 0;i<n;i++)
		color[i]=-1;
	queue<int> q;
	q.push(source);
	visited[source] = 1;
    color[source] = 1;
	while(!q.empty())
	{
		int u =q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++)
		{
            int child = graph[u][i];
			if(!visited[child] && color[child]==-1)
            {
                color[child] = 1-color[u];
				q.push(child);
                visited[child]  =1;
            }
			else if(visited[child] && color[child]==color[u])
				return false;

		}
	}
    return true;
}

int main()
{

	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}

	bipartiteCheck(0) ? cout << "Yes" : cout << "No";
	return 0;
}