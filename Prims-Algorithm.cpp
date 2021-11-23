#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<pair<int,int>>> &graph, int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});

    vector<int> vis(V+1,false);
    int total = 0;

    while(!pq.empty()){
        int curWt = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if(!vis[curNode])total+=curWt;
        vis[curNode] = true;
        for(auto &childNode : graph[curNode]){
            if(!vis[childNode.second]){
                pq.push(childNode);
            }
        }
    }
    return total;
}

int main(){

    int V, E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> graph(V+1,vector<pair<int,int>>());

    int i=0,u,v,w;
    while(i<E){
        cin>>u>>v>>w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
        ++i;
    }
    cout<<solve(graph,V+1)<<endl;
    return 0;
}