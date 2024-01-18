#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> board(50,vector<int>(50,0));
vector<vector<bool>> visited(50,vector<bool>(50,false));
queue<pair<int,int>> q;
int M, N, K;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void init(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            visited[i][j]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){ 
        cin>>M>>N>>K;
        init();
        vector<pair<int,int>> warms;
        for(int i=0; i<K; ++i){
            int x,y;

            cin>>x>>y;
            warms.push_back({x,y});
            board[y][x] = t;
        }
        int result = 0;
        for(int i=0; i<warms.size();++i){
            int tx = warms[i].first;
            int ty = warms[i].second;
            if(!visited[ty][tx]) result++;
            visited[ty][tx] = true;
            q.push({tx,ty});
            while(!q.empty()){
                tx = q.front().first;
                ty = q.front().second;
                q.pop();
                for(int j=0; j<4; ++j){
                    int nx = tx+dx[j];
                    int ny = ty+dy[j];
                    if(nx<M && nx>=0 && ny<N && ny>=0){
                        if(board[ny][nx]==t && !visited[ny][nx]){
                            q.push({nx,ny});
                            visited[ny][nx]=true;
                        }
                    }
                }
            }
        }
        cout<<result<<'\n';
    }
}