#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[6] = {1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz [6] ={0,0,0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M,N,H;

    cin>>M>>N>>H;

    int cnt=0;
    vector<vector<vector<int>>> storage(100,vector<vector<int>>(100, vector<int>(100,0)));
    vector<vector<vector<bool>>> visited(100,vector<vector<bool>>(100, vector<bool>(100,false)));
    queue<pair<int,pair<int,pair<int,int>>>> q;

    int x=0;
    for(int i=0;i<H;++i){
        for(int j=0;j<N;++j){
            for(int m=0; m<M;++m){
                int tmp;
                cin>>tmp;

                storage[i][j][m]=tmp;
                if(tmp == 1){
                    q.push({0,{i,{j,m}}});
                    visited[i][j][m] = true;
                    cnt++;
                }
                else if(tmp == -1) x++;
            }
        }
    }

    int num = M*N*H - x;
    int answer=0;
    while(!q.empty()){
        int z = q.front().second.first;
        int y = q.front().second.second.first;
        int x = q.front().second.second.second;
        int d = q.front().first;
        answer = max(d,answer);
        q.pop();

        for(int i=0; i<6; ++i){
            int tx = x+dx[i];
            int ty = y+dy[i];
            int tz = z+dz[i];
            if(tx>=0 && ty>=0 && tz>=0 && tx<M && ty<N && tz<H){
                if(!visited[tz][ty][tx] && storage[tz][ty][tx] == 0){
                    q.push({d+1,{tz,{ty,tx}}});
                    visited[tz][ty][tx] = true;
                    cnt++;
                }
            }
        }
    }
    if(cnt == num) cout<<answer;
    else cout<<-1;

    return 0;
}