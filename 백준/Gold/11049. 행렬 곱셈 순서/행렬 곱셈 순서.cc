#include<iostream>
#define INF 2000000000
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    int matrix[501][2]={0,};
    int dp[501][501] = {0,};

    for(int i=1; i<=N;++i){
        cin>>matrix[i][0]>>matrix[i][1];
    }

    for(int k=1; k<N; ++k){
        for(int i=1; i+k<=N; ++i){
            dp[i][i+k]=INF;
            for(int j=i; j<i+k; ++j){
                dp[i][i+k] = min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+matrix[i][0]*matrix[j][1]*matrix[i+k][1]);
            }
        }
    }

    cout<<dp[1][N];


}