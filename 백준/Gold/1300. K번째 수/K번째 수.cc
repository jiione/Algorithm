#include<iostream>
#include<algorithm>

typedef long long ll;

ll K,N;
ll cnt;

using namespace std;

ll count(ll mid){
    ll sum = 0;

    for(int i=1; i<=N; ++i){
        sum+=min(N,mid/i);
    }

    return sum;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>K;

    ll start = 0;
    ll end = N*N;

    while(end>=start){
        ll mid = (end+start)/2;

        cnt = count(mid);

        if(cnt>=K){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }

    cout<< start;
}