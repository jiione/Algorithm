#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<bool> visited;
vector<int> graph;
int N,M;
void DFS(int n, int cnt){
    if(M==cnt){
        for(auto it : graph){
            cout<<it<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            visited[i]=true;
            graph.push_back(i);
            DFS(i,cnt+1);
            graph.pop_back();
            visited[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    visited.assign(N+1,false);

    for(int i=1;i<=N;i++){
        visited[i] = true;
        graph.push_back(i);
        DFS(i,1);
        graph.pop_back();
        visited[i] =false;
    }
}