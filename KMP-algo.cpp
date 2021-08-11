#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n=s.size(), len=0,i=1;
    vector<int> pi(n,0);
    while(i<n){
        if(s[len]==s[i]){
            pi[i]=len+1;
            ++i;
            ++len;
        }else{
            if(len!=0){
                len=pi[len-1];
            }else{
                pi[i]=0;
                ++i;
            }
        }
    }
    return pi;
}

int main(){
    string t = "abcabcd";
    string s = "ca";
    int pos=-1;
    vector<int> pi = prefix_function(s);
    int i(0), j(0);
    while(i<t.size()){
        if(t[i]==s[j]){
            ++i;
            ++j;
        }else{
            if(j!=0){
                j=pi[j-1];
            }else{
                i++;
            }
        }
        if(j==s.size()){
            pos=i-s.size();
            break;
        }
    }

    cout<<pos<<endl;
}
