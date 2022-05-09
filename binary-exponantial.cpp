#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define int long long
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5+2;

ll binaryExponential(int x, int n){
   if(n==0) return 1;
   if(n==1) return x;
   ll res = binaryExponential(x,n/2);
   if(n&1) return res*res*x;
   else return res*res;
}

int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int x,n;
      cin>>x>>n;
      ll res = binaryExponential(x,n);
      print(res);
   }//while
   return 0;
}
