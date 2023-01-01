#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int result=0;
int N;
vector<pair<int,int> > board;
vector<bool> visited;

void dfs(int cnt){
    if(cnt==N){
        result++;
        return;
    }

    for(int j=0;j<N;j++){
        if(visited[j]==true) continue;
        bool check = false;
        for(auto it : board){
            if((it.first-cnt)/(double)(it.second-j)==1 || (it.first-cnt)/(double)(it.second-j)==-1){
                check = true;
                break;
            }
        }
        if(check==true){
            check=false;
            continue;
        }
        visited[j]=true;
        board.push_back(make_pair(cnt,j));
        dfs(cnt+1);
        board.pop_back();
        visited[j]=false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;

    visited.assign(N,false);
    for(int i=0;i<N;i++){
        visited[i]=true;
        board.push_back(make_pair(0,i));
        dfs(1);
        board.pop_back();
        visited[i]=false;
    }

    cout<<result;

     
}