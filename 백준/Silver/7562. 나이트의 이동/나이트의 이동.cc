#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

void init(vector<vector<int>> &v, int n){
    for(int i=0;i<n;++i){
        for(int j=0; j<n; ++j){
            v[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> visited(300,vector<int>(300,0));
    
    int T;
    cin>>T;
    while(T--){
        int I;
        cin>>I;
        init(visited, I);
        int cx,cy, tx,ty;
        cin>>cx>>cy;
        cin>>tx>>ty;
        queue<pair<int,int>> q;
        q.push({cx,cy});
        visited[cy][cx] = 1;

        while(!q.empty()){
            cx = q.front().first;
            cy = q.front().second;
            q.pop();
            if(cx == tx && cy == ty){
                cout<<visited[cy][cx] - 1<<endl;
                break;
            }

            for(int i=0; i<8; ++i){
                int x = cx+dx[i];
                int y = cy+dy[i];
                if(x>=0 && x<I && y>=0 && y<I){
                    if(visited[y][x]==0){
                        q.push({x,y});
                        visited[y][x] = visited[cy][cx]+1;
                    }
                }
            }
        }
    }
    return 0;
}