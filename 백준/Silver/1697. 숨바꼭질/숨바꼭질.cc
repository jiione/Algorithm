#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int N,K;
    cin>>N>>K;
    vector<bool> visited(100001,false);
    queue<pair<int,int>> q;
    q.push({N,0});
    visited[N] = true;
    while(!q.empty()){
        int t = q.front().first;
        int s = q.front().second;
        q.pop();
        if(t==K){
            cout<<s<<endl;
            break;
        }
        if(t+1<=100000 && !visited[t+1]){
            q.push({t+1,s+1});
            visited[t+1] = true;
        }
        
        if(t*2<=100000&&!visited[t*2]){
            q.push({t*2,s+1});
            visited[t*2] = true;
        }
        if(t-1>=0 && !visited[t-1]){
            q.push({t-1,s+1});
            visited[t-1] = true;
        }
        

    }

    return 0;

}