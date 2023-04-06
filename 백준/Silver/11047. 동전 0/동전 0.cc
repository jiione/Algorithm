#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[11]={0,};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    int cnt=0;

    cin>>N>>K;

    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    for(int i=N;K!=0;i--){
        int tmp =K/arr[i];
        cnt+=tmp;
        K-=tmp*arr[i];
    }
    cout<<cnt;
    return 0;
}
