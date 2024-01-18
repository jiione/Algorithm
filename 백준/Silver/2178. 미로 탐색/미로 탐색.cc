#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<vector<int>> board(N+1,vector<int>(M+1,0));
    vector<vector<bool>> visited(N+1,vector<bool>(M+1,false));
    string input;

    for(int i=1; i<=N;++i){
        cin>>input;
        for(int j=0; j<input.length();++j){
            if(input[j]-'0'!=0){
                board[i][j+1] = 10000;
            }
        }
    }

    queue<pair<int,int>> q;

    q.push({1,1});
    visited[1][1] = true;
    board[1][1] =1;


    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; ++i){
            int tx = x+dx[i];
            int ty = y+dy[i];

            

            if(tx>0 && tx<=M && ty>0 && ty<=N){
                if(board[ty][tx] && !visited[ty][tx]){
                    board[ty][tx] = min(board[ty][tx], board[y][x]+1);
                    q.push({tx,ty});
                    visited[ty][tx] = true;
                }
            }

            if(ty == N && tx == M){
                cout<<board[N][M];
                return 0; 
            }
        }

    }

    return 0;
}