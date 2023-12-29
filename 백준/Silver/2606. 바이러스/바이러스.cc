#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int cN, c;
int result=0;

void bfs(vector<vector<int>>& matrix, vector<bool>& visited){
    queue<int> q;

    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=1; i<=cN;++i){
            if(matrix[t][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
                result++;
            }
        }

    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>cN>>c;

    vector<vector<int>> matrix(cN+1,vector<int>(cN+1));
    vector<bool> visited(cN+1, false);

    for(int i=0; i<c; ++i){
        int u,v;
        cin>>u>>v;

        matrix[u][v]=1;
        matrix[v][u]=1;
    }

    bfs(matrix,visited);

    cout<<result<<endl;
}