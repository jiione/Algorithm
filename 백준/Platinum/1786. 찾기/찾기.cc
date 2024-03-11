#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> getPi(string p){
    int m = p.size(), j=0;

    vector<int> pi(m,0);

    for(int i=1; i<m; ++i){
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }

    return pi;
}

vector<int> kmp(string s, string p){
    int n = s.size(), m = p.size(), j=0;

    auto pi = getPi(p);
    vector<int> ans;

    for(int i=0; i<n; ++i){
        while(j>0 && s[i] != p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) {
                ans.push_back(i-j);
                j=pi[j];
            }
            else j++;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string t, p;

    getline(cin,t);
    getline(cin,p);

    
    auto ans = kmp(t,p);
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i+1<<" ";
    }
    cout<<endl;
}