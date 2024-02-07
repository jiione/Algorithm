#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAX_V 801
#define endl '\n'
#define INF 987654321

using namespace std;

vector<pair<int,int>> graph[MAX_V];
vector<int> dist(MAX_V, INF);
int N,E;
int v1,v2;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second>p2.second;
    }
};

void init(){
    for(int i =1; i<=N; ++i) dist[i] = INF;
}

void input(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>E;

    for(int i=0; i<E; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin>>v1>>v2;
}

void dijkstra(int start){
    init();
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({start,0});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().second;
        int cur = pq.top().first;
        pq.pop();

        for(pair<int,int> p : graph[cur]){
            int ncost = p.second + cost;
            int next = p.first;

            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.push({next,ncost});
            }
        }
    }
}

void solution(){
    dijkstra(1);
    int s_v1 = dist[v1];
    int s_v2 = dist[v2];

    dijkstra(v1);
    int v1_v2 = dist[v2];
    int v1_n = dist[N];

    dijkstra(v2);
    int v2_n = dist[N];

    int a = s_v1+v1_v2+v2_n;
    int b= s_v2+v1_v2+v1_n;

    int result = INF;

    result = min(a,result);
    result = min(b, result);
    
    if(result>=INF || v1_v2>=INF) cout<<-1<<endl;
    else cout<<result;

}
int main(){
    input();
    solution();
    return 0;
}