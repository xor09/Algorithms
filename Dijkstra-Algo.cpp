//single source shortest path
// using BFS + priority_queue;
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7;

struct cmp{
	bool operator()(pair<int,int>&a, pair<int,int>&b){
		return a.second>b.second;
	}
};

void dijkstra(vector<vector<pair<int,int>>>& graph, vector<int>& distance){
	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
	distance[0]=0;
	pq.push({0,0});

	while(!pq.empty()){
		int u = pq.top().first;
		int uwt = pq.top().second;
		pq.pop();

		if(uwt > distance[u]) continue;

		for(auto &child : graph[u]){
			if(distance[child.first] > distance[u]+child.second){
				distance[child.first] = distance[u]+child.second;
				pq.push({child.first,distance[child.first]});
			}
		}
	}
	return;
}

int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n,m;
      cin>>n>>m;
	  vector<vector<pair<int,int>>> graph(n);
	  vector<int> distance(n,INT_MAX);
	  int u,v,wt;
      while(m--){
		cin>>u>>v>>wt;
		u--;
		v--;
		graph[u].push_back({v,wt});
	  }
	  dijkstra(graph,distance);
	  for(int i=1;i<n;++i) printc(distance[i]);
	  cout<<endl;	
   }//while
   return 0;
}