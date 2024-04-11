#include<iostream>
#include<algorithm>

using namespace std;

int dp[7][7][3];
int map[7][7];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        for(int j=0; j<m; ++j){
            cin>>map[i][j];

            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = map[i][j];
            if(j==0) dp[i][j][0] = 1000;
            else if(j==m-1) dp[i][j][2] = 1000;
        }
    }

    for(int i=1; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(j!=0) dp[i][j][0] += min(dp[i-1][j-1][1],dp[i-1][j-1][2]);
            if(j!=m-1) dp[i][j][2] += min(dp[i-1][j+1][0],dp[i-1][j+1][1]);
            dp[i][j][1] += min(dp[i-1][j][0],dp[i-1][j][2]);
        }
    }

    int result = 1000;

    for(int i=0; i<m; ++i){
        for(int j=0;j<3;++j){
            result = min(result,dp[n-1][i][j]);
        }
    }

    cout<<result<<endl;
}