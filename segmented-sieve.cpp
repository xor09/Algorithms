#include <bits/stdc++.h>
#define maxN 1000001
using namespace std;

// code starts

vector<int> sieve(){
    bool isPrime[maxN];
    for(int i=0;i<maxN;++i) isPrime[i]=true;
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<maxN; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<maxN; j+=i){
                isPrime[j]=false;
            }
        }
    }
    
    vector<int> primes;
    
    for(int i=2;i<maxN;++i){
        if(isPrime[i]) primes.push_back(i);
    }

    return primes;
}

long long printPrimes(long long l, long long r, vector<int>& primes){
    bool isPrime[r-l+1];

    for(int i=0; i<r-l+1; ++i){
        isPrime[i]=true;
    }

    for(int i=0; primes[i]*(long long)primes[i] < r; ++i){
        int curPrime = primes[i];
        long long base = (l/curPrime)*curPrime;
        if(base < curPrime) base+=curPrime;
        for(long long j=base; j<=r; j+=curPrime){
            isPrime[j-l]=false;
        }
        if(base==curPrime){
            isPrime[base-l] = true;
        }
    }

    long long count=0;
    for(int i=0;i<r-l+1;++i){
        if(isPrime[i]) ++count;
    }
    return count;
}

// code ends

signed main(){
    vector<int> primes = sieve();
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        cout<<printPrimes(l,r,primes); 
    }
    return 0;
}