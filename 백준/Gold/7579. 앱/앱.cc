#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int dp[101][10001] = {0,};
    int mem[101];
    int cost[101];

    int N,M;
    cin>>N>>M;

    int sum=0;

    for(int i=1; i<=N; ++i){
        cin>>mem[i];
    }

    for(int i=1; i<=N; ++i){
        cin>>cost[i];
        sum+=cost[i];
    }

    for(int i=1; i<=N; ++i){
        for(int j=0; j<=sum;++j){
            if(j>=cost[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i]]+mem[i]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }

    for(int i=0;i<=10001;++i){
        if(dp[N][i]>=M){
            cout<<i<<endl;
            break;
        }
    }
}