#include<iostream>
#include<cmath>

#define y "Y "
#define n "N "

using namespace std;

bool dp[31][15001]={false};
int weight[30];
int N,M;

void solve(int i, int w){
    if(i>N || dp[i][w] ) return;
    dp[i][w] = true;
    solve(i+1,w+weight[i]);
    solve(i+1,abs(w-weight[i]));
    solve(i+1,w);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>weight[i];
    }

    cin>>M;
    solve(0,0);
    for(int i=1; i<=M; ++i){
        int x;
        cin>>x;
        if(x<=15000 && dp[N][x]) cout<<y;
        else cout<<n;
    }
    
    return 0;

}