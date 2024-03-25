#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int gold[1001];
    int silver[1001];
    int bronze[1001];

    int N,K;
    cin>>N>>K;
    for(int i=1; i<=N ;++i){
        int n,g,s,b;
        cin>>n>>g>>s>>b;
        gold[n] = g;
        silver[n] = s;
        bronze[n] = b;
    }
    int result =1;
    for(int i=1; i<=N; ++i){
        if(gold[i]>gold[K]) result++;
        else if(gold[i] == gold[K]){
            if(silver[i]>silver[K]) result++;
            else if(silver[i] == silver[K]){
                if(bronze[i] > bronze[K]) result++;
            }
        }
    }

    cout<<result<<endl;
}