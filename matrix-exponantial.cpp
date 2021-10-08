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


vector<vector<int>> matrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B){
   int size = A.size();
   vector<vector<int>> C(size,vector<int>(size,0));

   for(int i=0;i<size;++i){
      for(int j=0;j<size;++j){
         for(int k=0;k<size;++k){
            C[i][j]+=A[i][k]*B[k][j];
         }
      }
   }
   return C;
}


vector<vector<int>> matrixExponential(vector<vector<int>>& A, int n){
   if(n==1) return A;
   vector<vector<int>> resultby2 = matrixExponential(A,n/2);
   vector<vector<int>> result = matrixMultiplication(resultby2,resultby2);

   if(n&1) return matrixMultiplication(result,A);
   else return result;
}


int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<vector<int>> A={ {1,1},
                              {1,0} };
      vector<vector<int>> ans = matrixExponential(A,n);
      for(int i=0;i<ans.size();++i){
         for(int j=0;j<ans[0].size();++j){
            printc(ans[i][j]);
         }
         cout<<endl;
      }
   }//while
   return 0;
}