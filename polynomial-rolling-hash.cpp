#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int polynomial_rolling_hash(string key){
    long long int value = 0, p=31, p_power=1;
    for(auto &ch : key){
        value = (value + (ch-'a'+1)*p_power) % MOD;
        p_power = (p_power*p) % MOD;
    }
    return value;
}

int main(){
    string s = "abb";
    cout<<polynomial_rolling_hash(s)<<endl;
}