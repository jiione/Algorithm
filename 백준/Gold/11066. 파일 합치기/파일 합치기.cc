#include<iostream>
#define endl '\n'
#define INF 1000000000
using namespace std;
int dp[501][501] = {0,};
int sum[501]={0,};

void init(int K){
    for(int i=1;i<=K-1;++i){
        for(int j=i+1;j<=K;++j) dp[i][j]=INF;
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>K;

        init(K);
        int tmp;

        for(int i=1; i<=K; ++i){
            cin>>tmp;
            sum[i] = sum[i-1]+tmp;
        }

        for(int k=1; k<=K-1;++k){ //간격
            for(int i=1; i<=K-k;++i){//시작 지점
                for(int j=i;j<=i+k;++j){//중간 자기
                    dp[i][i+k] = min(dp[i][i+k],dp[i][j]+dp[j+1][i+k] +sum[i+k]-sum[i-1]);
                }
            }
        }

        cout<<dp[1][K]<<endl;
    }
}