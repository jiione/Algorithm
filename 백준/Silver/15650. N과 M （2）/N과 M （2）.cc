#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> v;
    for(int i=1;i<=N;i++){
        v.push_back(i);
    }
    vector<bool> visited (v.size(),false);
    for(int i=0;i<M;i++){
        visited[i]=true;
    }

    do{
        for(int i=0;i<N;i++){
            if(visited[i]==true){
                cout<<v[i]<<" ";
            }
        }
        cout<<'\n';
    }while(prev_permutation(visited.begin(),visited.end()));
}