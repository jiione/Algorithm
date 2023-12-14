#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> cnt(1000001,0);
    vector<int> numbers(N+1,0);
    vector<int> result(N+1,0);

    stack<pair<int,int>> s;

    for(int i=1; i<=N;++i){
        cin>>numbers[i];
        cnt[numbers[i]]++;
    }

    for(int i=N; i>0;--i ){
        int n = cnt[numbers[i]];
        while(!s.empty() && s.top().first<=n) s.pop();
        if(s.empty()) result[i]=-1;
        else result[i]=s.top().second;

        s.push(make_pair(n,numbers[i]));
    }

    for(int i=1; i<=N;++i){
        cout<<result[i]<<" ";
    }
}