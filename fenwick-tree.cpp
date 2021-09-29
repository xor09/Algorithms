#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7; 


void generateFenwickTreeNlogN(vector<int>, int);
void update(int ,int, int);
int prefixSum(int);
int query(int,int);

vector<int> fenwickArray(1000005,0);
void generateFenwickTreeNlogN(vector<int> arr, int n){
    for(int i=1;i<=n;++i){
        update(i,arr[i],n);
    }
}

int prefixSum(int idx){
    int sum=0;
    while(idx>0){
        sum+=fenwickArray[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int query(int l, int r){
    return prefixSum(r)-prefixSum(l-1);
}

void update(int idx, int delta, int n){
    idx+=1; //as we take 1 base indexing and we update vale with 0 base index;
    while(idx<=n){
        fenwickArray[idx]+=delta;
        idx+=(idx&-idx);
    }
}

int32_t main(){
    fastio;
    ll t=1;
    while(t--){
       int n;
       cin>>n;
       vector<int> arr(n+1,0);
       for(int i=1;i<=n;++i){
        cin>>arr[i];
       }
       generateFenwickTreeNlogN(arr,n);
       int noOfQ;
       cin>>noOfQ;
       char ch;
       int l, r;
       while(noOfQ--){
        cin>>ch>>l>>r;
        if(ch=='q') print(query(l,r));
        else if(ch=='u') update(l,r,n);
       }
    }
    return 0;
}