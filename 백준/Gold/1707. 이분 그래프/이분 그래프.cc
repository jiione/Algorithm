#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX_V 20000+1
#define endl '\n'

using namespace std;

vector<int> visited(MAX_V, 0); 
vector<int> graph[MAX_V];
bool check = true;

void init(int v){
    for(int i=1; i<=v; ++i){
        visited[i] = 0;
        graph[i].clear();
    }

    check = true;
}

void bfs(int start){
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i : graph[v]){
            if(visited[i] == visited[v]){
                check = false;
                return;
            }
            else if(visited[i] == 0){
                if(visited[v] == 1) visited[i] = 2;
                else if(visited[v] == 2) visited[i] = 1;
                q.push(i);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K;
    cin>>K;

    while(K--){
        int V, E;
        cin>>V>>E;

        for(int i=0; i<E; ++i){
            int u,v;
            cin>>u>>v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1; i<=V; ++i){
            if(visited[i]==0) bfs(i);
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        init(V);
    }

}