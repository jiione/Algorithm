#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> numbers(N+1,0);
    vector<int> result(N+1,0);

    stack<int> s;

    for(int i=1; i<=N;++i){
        cin>>numbers[i];
    }

    for(int i=N; i>0;--i ){
        int n = numbers[i];
        while(!s.empty() && s.top()<=n) s.pop();
        if(s.empty()) result[i]=-1;
        else result[i]=s.top();

        s.push(n);
    }

    for(int i=1; i<=N;++i){
        cout<<result[i]<<" ";
    }
}