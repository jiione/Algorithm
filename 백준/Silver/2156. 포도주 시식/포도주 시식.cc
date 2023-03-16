#include <iostream>
#include <algorithm>

using namespace std;

int arr [10001]= {0,};
int dp [10001]={0,};

int main(void){
    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3]= max(max(arr[1],arr[2])+arr[3],dp[2]);
    for(int i=4;i<=N;i++){
        dp[i]=max(max(arr[i]+arr[i-1]+dp[i-3],arr[i]+dp[i-2]),dp[i-1]);
    }

    int max=0;

    for(int i=1;i<=N;i++){
        if(dp[i]>=max) max=dp[i];
    }

    cout<<max;
}