#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
int N,M;
void dfs(int n,int cnt){
    if(cnt==M){
        for(auto it : v){
            cout<<it<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        if(i>=n){
            v.push_back(i);
            dfs(i,cnt+1);
            v.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;

    for(int i = 1; i<=N;i++){
        v.push_back(i);
        dfs(i,1);
        v.pop_back();
    }
     
}