#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long arr[1001]={0,};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    long long cnt=0;

    cin>>N>>M;

    long long sum = 0;
    long long tmp;
    for(int i=1; i<=N; i++){
        cin >> tmp;
        sum+=tmp;
        arr[sum%M]++;
    }

    for(int i=0;i<=1000;i++){
        cnt+=arr[i]*(arr[i]-1)/2;
    }

    cout<<cnt+arr[0]<<'\n';
    return 0;
}
