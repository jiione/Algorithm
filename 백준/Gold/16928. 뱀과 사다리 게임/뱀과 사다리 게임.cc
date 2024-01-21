#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> lOs(101,0);
    vector<bool> visited(101, false);
    queue<pair<int,int>> q;

    int N,M;
    cin>>N>>M;

    for(int i=0; i<N+M; ++i){
        int start, end;
        cin>>start>>end;

        lOs[start] = end;
    }

    q.push({1,0});
    visited[1] = true;

    while(!q.empty()){
        int cnt = q.front().second;
        int cs = q.front().first;
        q.pop();

        for(int i=1; i<=6;++i){
            int ns = cs+i;
            if(ns == 100){
                cout<<cnt+1<<endl;
                return 0;
            }
            if(!visited[ns]){
                if(lOs[ns] == 0){
                    q.push({ns,cnt+1});
                    visited[ns] = true;
                }
                else{
                    q.push({lOs[ns],cnt+1});
                    visited[ns] = true;
                    visited[lOs[ns]] = true;
                }
                
            }
        }
    }


}