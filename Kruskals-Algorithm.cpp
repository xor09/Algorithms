#include <bits/stdc++.h>
using namespace std;

struct Node{
    int u,v,w;
};

vector<Node> arr;
vector<int> parent;
vector<int> rankk;
int ans = 0;

struct cmp{
    bool operator()(struct Node x, struct Node y){
        return x.w < y.w;
    }
};

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void unionDSU(struct Node a){
    int x=find(a.u), y=find(a.v);
    if(x==y) return;
    if(rankk[x] > rankk[y]) parent[y] = x;
    else if(rankk[y] > rankk[x]) parent[x] = y;
    else{
        parent[x] = y;
        rankk[y]+=1;
    }
    ans+=a.w;
}

int32_t main(){
    ans=0;
    int N,M;
    cin>>N>>M;
    parent.resize(N+1);
    for(int i=0; i<=N; ++i) parent[i]=i;
    rankk.resize(N+1,1);
    while(M--){
        int u,v,w;
        cin>>u>>v>>w;
        struct Node newNode;
        newNode.u = u;
        newNode.v = v;
        newNode.w = w;
        arr.push_back(newNode);
    }
    sort(arr.begin(),arr.end(),cmp());
    for(int i=0; i<arr.size(); ++i){
        unionDSU(arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}