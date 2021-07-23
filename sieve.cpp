#include <bits/stdc++.h>
#define maxN 1000001
using namespace std;

bool isPrime[maxN-1];
int sieve(){
    for(int i=0;i<=maxN;++i) isPrime[i]=true;
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=maxN; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<=maxN; j+=i){
                isPrime[j]=false;
            }
        }
    }
    return 0;
}

signed main(){
    sieve();
    cout<<isPrime[97]<<endl;
    return 0;
}