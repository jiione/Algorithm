#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

struct node{
    int n;
    vector<node*> nexts; 
}nodes[100001];

int visited[100001] = {0,};



void init(int N){
    for(int i=1; i<=N;++i){
        nodes[i].n=i;
    }
}

int cnt=0;

void dfs(int n){
    for(node* nd : nodes[n].nexts){
        if(!visited[nd->n]){
            visited[nd->n]=++cnt;
            dfs(nd->n);
            
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N,M,R;

    cin>>N>>M>>R;
    init(N);

    for(int i=0; i<M; ++i){
        int a,b;
        cin>>a>>b;
        nodes[a].nexts.push_back(&nodes[b]);
        nodes[b].nexts.push_back(&nodes[a]);
        
    }

    for(int i=1; i<=N; ++i){
        sort(nodes[i].nexts.begin(),nodes[i].nexts.end()
        ,[](node* a, node* b){
            return a->n>b->n;
        });
    }

    visited[R]=++cnt;
    dfs(R);

    for(int i=1; i<=N; ++i){
        cout<<visited[i]<<endl;
    }
    return 0;

}