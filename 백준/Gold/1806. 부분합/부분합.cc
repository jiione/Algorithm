#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_LEN 1000000

using namespace std;

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int N;
    int S;

    cin>>N>>S;

    vector<int> arr(N);

    for(int i=0;i<N; ++i){
        cin>>arr[i];
    }

    int start = 0;
    int end = 0;
    int sum = arr[0];
    int result=MAX_LEN;

    while(start<=end && end<N){

        if(sum>=S){
            result = min(result,end-start+1);
            sum-=arr[start++];   
        }
        else{
            sum+=arr[++end];
        }

    }

    if(result == MAX_LEN) cout<<0<<endl;
    else cout<<result<<endl;

    return 0;

}