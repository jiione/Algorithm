#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    vector<int> indegree(n+1,0);
    vector<vector<int>> graph(n+1,vector<int>());
    vector<int> result(0);

    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        graph[a].emplace_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for(int i=1; i<=n; ++i){
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()){
        int m = q.front();
        result.emplace_back(m);
        for(int i : graph[m]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
        q.pop();
    }

    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;
}