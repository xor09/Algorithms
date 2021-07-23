// GCD(a,b) has the property that   ax + by = gcd(a,b)

#include <bits/stdc++.h>
using namespace std;

// code start

struct triplet{
    int x, y, gcd;
};

struct triplet extendedgcd(int a, int b){
    if(b==0){
        struct triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }

    struct triplet smallAns = extendedgcd(b,a%b);

    struct triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x-(a/b)*smallAns.y;
    return ans;
} 

// code end

int main(){
    struct triplet ans = extendedgcd(6,3);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}