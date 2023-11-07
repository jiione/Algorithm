#include<iostream>
#define endl '\n'
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int map[501][501];
int dp[501][501] = {0,};
bool visited[501][501] ={false};
int N,M;

int dfs(int x, int y){
    if(x==M && y==N) return 1;
    if(visited[y][x]) return dp[y][x];
    visited[y][x] = true;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx > 0 && ny > 0 && nx <= M && ny <= N){
            if(map[y][x] > map[ny][nx]){
                dp[y][x] += dfs(nx,ny);
            }
        } 
    }    
    return dp[y][x];
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M;++j)
            cin>>map[i][j];
    
    cout<<dfs(1,1)<<endl;
}