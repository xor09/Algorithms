#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
const int N = 1e5+2;

int phi[1000001];
void phi_function(int n){
   for(int i=1;i<=n;++i) phi[i]=i;
   for(int i=2;i<=n;++i){
      if(phi[i]==i){
         for(int j=i;j<=n;j+=i){
            phi[j] /= i;
            phi[j] *= (i-1);
         }
      }
   }
}

int32_t main(){
   fastio;
   phi_function(1000000);
   const clock_t begin_time = clock();
   ll t=1;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      print(phi[n]);
   }//while
   timeTaken;
   return 0;
}
