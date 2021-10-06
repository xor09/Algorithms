#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define int long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7;


vector<vector<int>> farr(1005,vector<int>(1005,0));
vector<vector<int>> arr(1005,vector<int>(1005,0));
void generateFenwickTree2D(int, int);
void update(int, int, int, int, int);
int query(int, int, int, int);
int prefixSum(int, int);

void generateFenwickTree2D(int row, int col){
   for(int i=1;i<=row;++i){
      for(int j=1;j<=col;++j){
         update(i,j,arr[i][j],row,col);
      }
   }
}

 void update(int x, int y, int val, int row, int col){
   int xdash = x;
   while(xdash<=row){
      int ydash=y;
      while(ydash<=col){
         farr[xdash][ydash]+=val;
         ydash+=(ydash&-ydash);
      }
      xdash+=(xdash&-xdash);
   }
 }

 int query(int x1, int y1, int x2, int y2){
   int inc1 = prefixSum(x2,y2);
   int exc1 = prefixSum(x1-1,y2);
   int exc2 = prefixSum(x2,y1-1);
   int inc2 = prefixSum(x1-1,y1-1);
   return inc1-exc1-exc2+inc2;
 }

 int prefixSum(int x, int y){
   int sum=0;
   int xdash = x;
   while(xdash>0){
      int ydash=y;
      while(ydash>0){
         sum+=farr[xdash][ydash];
         ydash-=(ydash&-ydash);
      }
      xdash-=(xdash&-xdash);
   }
   return sum;
 }

int32_t main(){
    fastio;
    ll t=1;
    while(t--){
       int row,col;
       cin>>row>>col;
       for(int i=1;i<=row;++i){
         for(int j=1;j<=col;++j){
            cin>>arr[i][j];
         }
       }
       generateFenwickTree2D(row,col);

       int q;
       cin>>q;
       char ch;
       int x1,y1,x2,y2,val;
       while(q--){
         cin>>ch;
         if(ch=='q'){
            cin>>x1>>y1>>x2>>y2;
            int ans = query(x1,y1,x2,y2);
            print(ans);
         }else if(ch=='u'){
            cin>>x1>>y1>>val;
            update(x1,y1,val,row,col);
         }
       }
   }//while
   return 0;
}