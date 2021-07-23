#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    for (int d = 2; d*d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main(){
    cout<<isPrime(6)<<endl;
    return 0;
}