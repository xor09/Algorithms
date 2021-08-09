#include <bits/stdc++.h>
using namespace std;

vector<int> z_algo(string s){
	int L = 0, R = 0, n=s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) 
    {
        if (i > R) 
        {
            L = R = i;
            while (R < n && s[R-L] == s[R]) 
            {
                R++;
            }
            z[i] = R-L; 
            R--;
        } 
        else 
        {
            int k = i-L;
            if (z[k] < R-i+1) 
            {
                z[i] = z[k];
            } 
            else 
            {
                L = i;
                while (R < n && s[R-L] == s[R]) 
                {
                    R++;
                }
                z[i] = R-L; 
                R--;
            }
        }
    }
	return z;
}

int main(){
	string pat="aa" , str="aaaaaaaaaa";
	string total = pat+"$"+str;
	vector<int> z = z_algo(total);
	int count=0;
	for(int i=0; i<z.size(); ++i){
		if(z[i]==pat.size()){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}