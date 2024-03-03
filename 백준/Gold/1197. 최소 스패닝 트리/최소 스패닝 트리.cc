#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> parent(10001);


int Find(int x){
    if(parent[x] == x) return x;

    return parent[x] = Find(parent[x]);
}

void Uni(int u, int v){
    u = Find(u);
    v = Find(v);

    parent[v] = u;
}

bool Same(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y) return true;
    else return false;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int V,E;
    cin>>V>>E;
    vector<pair<int,pair<int,int>>> graph(E);

    for(int i=0; i<E; ++i){
        int a,b,c;
        cin>>a>>b>>c;

        graph[i] = {c,{a,b}};
    }

    int result = 0;
    sort(graph.begin(), graph.end());
    for(int i=1; i<=V; ++i) parent[i] = i;
    for(int i=0; i<graph.size(); ++i){
        if(!Same(graph[i].second.first,graph[i].second.second)){
            Uni(graph[i].second.first,graph[i].second.second);
            result+=graph[i].first;
        }
    }

    cout<<result;

}