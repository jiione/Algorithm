#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int parent[101];

int Find(int x){
    if(parent[x] == x) return x;

    return parent[x] = Find(parent[x]);
}

void Uni(int u, int v){
    u = Find(u);
    v = Find(v);

    parent[u] = v;
}

bool SameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<double,double>> loc(n+1);
    vector<pair<double,pair<int,int>>> graph;
    for(int i=1; i<=n; ++i){
        double x, y;
        cin>>x>>y;

        loc[i] = {x,y};
        parent[i] = i;
    }

    for(int i=1; i<=n; ++i){
        double x1 = loc[i].first;
        double y1 = loc[i].second;
        for(int j=i+1; j<=n; ++j){
            double x2 = loc[j].first;
            double y2 = loc[j].second;

            double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2) * (y1-y2));
            graph.push_back({dist,{i,j}});
        }
    }

    sort(graph.begin(), graph.end());

    double result = 0;

    for(int i=0; i<graph.size(); ++i){
        double dist = graph[i].first;
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        
        if(!SameParent(u,v)){
            Uni(u,v);
            result+=dist;
        }
    }

    cout<<result<<endl;


}