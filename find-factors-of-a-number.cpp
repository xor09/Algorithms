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

vector<int> factors;
int findFactor(int n){
  factors.clear();
  for(int i=1;i*i<=n;++i){
    if(n%i==0){
      factors.push_back(i);
      if(n/i!=i) factors.push_back(n/i);
    }
  }
  return 0;
}

int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   //cin>>t;
   while(t--){
      int n;
      cin>>n;
      int temp = findFactor(n);
      for(auto &x : factors) cout<<x<<" ";
      nextline;
   
   }//while
   timeTaken;
   return 0;
}
