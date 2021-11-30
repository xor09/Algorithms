#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define int long long
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define pb push_back
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
const int N = 1e5;

vector<bool> sieveArr(N+1,true);
vector<int> prime;
void sieve(){
   sieveArr[0] = sieveArr[1] = false;
   for(ll i=2; i<=N; ++i){
      if(sieveArr[i]){
         prime.pb(i);
         for(ll j=i*i; j<=N; j+=i){
            sieveArr[j]=false;
         }
      }
   }
}

int32_t main(){
   fastio;
   //precompute
   sieve();
   const clock_t begin_time = clock();
   ll t=1;
   cin>>t;
   while(t--){
      ll m,n;
      cin>>m>>n;
      vector<bool> segment(n-m+1,true);

      for(auto &p : prime){
         if(p*p > n) break;

         int start = (m/p)*p;

         //special case
         if(p>=m && p<=n) start = 2*p;

         for(int j=start; j<=n; j+=p){
            if(j < m) continue;
            segment[j-m]=false;
         }
      }

      for(int i=m; i<=n; ++i){
         if(segment[i-m] && i!=1) print(i);
      }
      nextline;
   
   }//while
   //timeTaken;
   return 0;
}
