#include <bits/stdc++.h>
using namespace std;

int BoyerMooreVotingAlgo(vector<int>& arr){
    int size=arr.size(), ele = arr[0], count=1;
        for(int i=1;i<size;++i){
            if(arr[i] == ele) count++;
            else count--;
            if(count==0){
                ele = arr[i];
                count++;
            }
        }

        count=0;
        for(int i=0;i<size;++i){
            if(arr[i]==ele) count++;
        }
        return count>size/2 ? ele : -1;
}

int main(){
    vector<int> vec = {3,2,3,4,3,4,3};
    cout<<BoyerMooreVotingAlgo(vec)<<endl;
    return 0;
}