#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
 
#define MAX_NODES (int)1e5
 
using namespace std;
 
vector<vector<pair<int,int> > > g (MAX_NODES);
 
int dist[MAX_NODES];
 
int main ()
{
    int N,M;
    int from,to,weight;
    int start,end;
 
    scanf ("%d",&N);
    scanf ("%d",&M);
 
    for (int i=0;i<M;i++)
    {
        scanf ("%d",&from);
        scanf ("%d",&to);
        scanf ("%d",&weight);
 
        // Add Both The Undirected Edges And Weights Together
 
        g[from].push_back (make_pair (weight,to));
        g[to].push_back (make_pair (weight,from));
 
    }
 
    scanf ("%d",&start);
    scanf ("%d",&end);
 
    // Setting All Distances To Infinity And Visited To False
 
    for (int i=0;i<N;i++)
    {
        dist[i] = std::numeric_limits<int>::max();
    }
 
    // This Is The Prority Queue That Will Hold The The Distances And Corresponding Nodes
    priority_queue<pair<int,int> >  pq;
    pq.push (make_pair(0,start));
 
    dist[start] = 0; // Distance From Start To Itself Is 0
 
    while (!pq.empty ())
    {
        // Take Out The Current Minimum.
        pair<int,int> current = pq.top ();
        pq.pop ();
 
        for (vector<pair<int,int> >::iterator it = g[current.second].begin();it!=g[current.second].end();it++)
        {
            // Calculate The Minimum Distance To That Node
            int dist_now = dist[current.second] + it->first;
 
            // If We Got A Better Distance Then Add It To The Queue
            if (dist_now <= dist[it->second])
            {
                dist[it->second] = dist_now;
                pq.push (make_pair(dist_now,it->second));
 
            }
        }
    }
 
    // Print The Distance Of All The Nodes From The Start Node
    // NOTE :: If Distance Is 2147483647. It Means Infinity.
 
    for (int i=0;i<N;i++)
        printf ("Distance To %d is %d\n",i,dist[i]);
 
    return 0;
}