#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'
#define MAX_V 20001
#define INF 987654321

using namespace std;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second>p2.second;
    }
};

vector<pair<int,int>> graph[MAX_V];
vector<int> dist(MAX_V, INF);



void dijkstra(int V, int K){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({K,0});
    dist[K] = 0;

    while(!pq.empty()){
        int cost = pq.top().second;
        int cur = pq.top().first;
        pq.pop();

        for(pair<int,int> p : graph[cur]){
            int ncost = p.second;
            int next = p.first;

            if(dist[next]>cost+ncost){
                dist[next]=cost+ncost;
                pq.push({next,dist[next]});
            }
        }
    }

    for(int i=1; i<=V; ++i){
        if(dist[i]==INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
}

void solution(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int V,E,K;
    cin>>V>>E;
    cin>>K;
    for(int i=0; i<E; ++i){
        int u,v,w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
    }

    dijkstra(V,K);
}

int main(){
    solution();
    return 0;
}