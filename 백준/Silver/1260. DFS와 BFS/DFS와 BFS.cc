#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

#define endl '\n'

using namespace std;

int N,M,V;

void dfs(const vector<vector<int>>& matrix){
    stack<int> s;
    vector<bool> visited(N+1,false);
    s.push(V);

    while(!s.empty()){
        int cn = s.top();
        s.pop();
        if(!visited[cn]){
            visited[cn] = true;
            cout<<cn<<" ";
        }
        

        for(int i=matrix[cn].size()-1; i>=0; i--){
            int nn = matrix[cn][i];
            if(!visited[nn]){
                s.push(nn);
            }
        }
    }
    cout<<endl;
}

void bfs(const vector<vector<int>>& matrix){
    queue<int> q;
    vector<bool> visited(N+1, false);
    q.push(V);
    visited[V] = true;

    while(!q.empty()){
        int cn = q.front();
        q.pop();
        cout<<cn<<" ";

        for(int i=0; i<matrix[cn].size();++i){
            int nn = matrix[cn][i];

            if(!visited[nn]){
                q.push(nn);
                visited[nn] = true;
            }
        }
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin>>N>>M>>V;

    vector<vector<int>> matrix (N+1, vector<int>(0));

    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    for(int i=1; i<=N; ++i){
        sort(matrix[i].begin(),matrix[i].end());
    }

    dfs(matrix);
    bfs(matrix);

    return 0;
}