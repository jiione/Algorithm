#include<iostream>

using namespace std;

int dp[10001];
int coin[100];
int n,k;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>coin[i];
    }
    dp[0] =1;
    for(int i=0; i<n; ++i){
        int v = coin[i];

        for(int j = v; j<=k; ++j){
            dp[j] += dp[j-v];
        }
    }

    cout<<dp[k];
}