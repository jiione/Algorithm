#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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

void bfs(int n){
    queue<node*> q;
    q.push(&nodes[n]);
    visited[n] = ++cnt;
    while(!q.empty()){
        node* tNode = q.front();
        
        q.pop();
        for(node* t : tNode->nexts){
            if(!visited[t->n]){
                visited[t->n] = ++cnt;
                q.push(t);
            }
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

    bfs(R);

    for(int i=1; i<=N; ++i){
        cout<<visited[i]<<endl;
    }
    return 0;

}