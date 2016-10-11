#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int visited[112345], a,b,m,n;

bool isCycle(int current,int parent)
{

	visited[current] = 1;
	vector<int>::iterator it;
	for(it = graph[current].begin();it!=graph[current].end();it++)
	{
		if(!visited[*it])
		{	
			if(isCycle(*it,current))
                return true;
            
		}
			
		else if(*it!=parent)
				return true;
        	
	}
    
	return false;
}

int main()
{

	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}
	for(int i = 0;i<n;i++)
	{
		if(!visited[i])
		{
			if(isCycle(i,-1))
			{
				cout<<"Cycle present";
					return 0;
			}
		}
        
	}
    cout<<"Cycle not present";
    return 0;
}