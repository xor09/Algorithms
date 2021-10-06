//zero based indexing
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define int long long
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7;
 
const int maxL = 2*1e5;
int arr[maxL], tree[4*maxL];
void build(int root, int start, int end){
   if(start==end){
      tree[root]=arr[start];
      return;
   }
 
   int mid = start+(end-start)/2;
   build(2*root+1,start,mid);
   build(2*root+2,mid+1,end);
 
   tree[root] = tree[2*root+1]+tree[2*root+2];
}
 
int query(int root, int start, int end, int l, int r){
   if(l<=start and r>=end) return tree[root];
   if(l>end or r<start) return 0;
   
   int mid = start+(end-start)/2;
   int left = query(2*root+1,start,mid,l,r);
   int right = query(2*root+2,mid+1,end,l,r);
   return left+right;
}
 
void update(int root, int start, int end, int idx, int val){
   if(start==end){
      tree[root]=val;
      return;
   }
   int mid=start+(end-start)/2;
   if(idx<=mid) update(2*root+1,start,mid,idx,val);
   else update(2*root+2,mid+1,end,idx,val);
   tree[root]=tree[2*root+1]+tree[2*root+2];
}
 
int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      for(int i=0;i<n;++i){
         cin>>arr[i];
      }
      build(0,0,n-1);
 
      int a,l,r,idx,val;
      while(q--){
         cin>>a;
         if(a==2){
            cin>>l>>r;
            int x = query(0,0,n-1,l-1,r-1);
            print(x);
         }else if(a==1){
            cin>>idx>>val;
            update(0,0,n-1,idx-1,val);
         }
         
      }
   }//while
   return 0;
}