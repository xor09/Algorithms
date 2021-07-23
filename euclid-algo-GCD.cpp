#include <bits/stdc++.h>
using namespace std;

// code start

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

// code end

int main(){
    cout<<gcd(35,10)<<endl;
    return 0;
}