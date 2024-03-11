#include<iostream>
#include<vector>

using namespace std;

vector<int> getPi(string s){
    int n = s.size(), j=0;
    vector<int> pi(n,0);

    for(int i=1; i<n; ++i){
        while(j>0 && s[i] != s[j]) j=pi[j-1];
        if(s[i]==s[j]) pi[i] = ++j;
    }

    return pi;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int l; string s;
    cin>>l;
    cin>>s;

    auto pi = getPi(s);
    int n = pi.size();

    cout<<l-pi[n-1]<<endl;
}