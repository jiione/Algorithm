#include <iostream>
#include <queue>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int day=0;
    int col,row;
    int tmp;
    int num=0;
    cin>>col>>row;
    int **map = new int*[row];
    for(int i=0; i<row;i++){
        map[i]=new int[col];
    }
    queue<pair<int,int>> q;
    pair<int,int> p;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[i][j];
            if(map[i][j]==1) q.push(make_pair(i,j));
        }
    }
    num=q.size();
    while(!q.empty()){
        if(num==0){
            num=q.size();
            day++;
        }
        p=q.front();
        q.pop();
        if(p.first==0){
            if(map[p.first+1][p.second]==0){
                q.push(make_pair(p.first+1,p.second));
                map[p.first+1][p.second]=1;
            }
        }
        else if(p.first==row-1){
            if(map[p.first-1][p.second]==0){
                q.push(make_pair(p.first-1,p.second));
                map[p.first-1][p.second]=1;
            }
        }
        else{
            if(map[p.first+1][p.second]==0){
                q.push(make_pair(p.first+1,p.second));
                map[p.first+1][p.second]=1;
            }
            if(map[p.first-1][p.second]==0){
                q.push(make_pair(p.first-1,p.second));
                map[p.first-1][p.second]=1;
            }
        }

        if(p.second==0){
            if(map[p.first][p.second+1]==0){
                q.push(make_pair(p.first,p.second+1));
                map[p.first][p.second+1]=1;
            }
        }
        else if(p.second==col-1){
            if(map[p.first][p.second-1]==0){
                q.push(make_pair(p.first,p.second-1));
                map[p.first][p.second-1]=1;
            }
        }
        else{
            if(map[p.first][p.second+1]==0){
                q.push(make_pair(p.first,p.second+1));
                map[p.first][p.second+1]=1;
            }
            if(map[p.first][p.second-1]==0){
                q.push(make_pair(p.first,p.second-1));
                map[p.first][p.second-1]=1;
            }
        }
        num--;
    }

    for(int i=0; i<row;i++){
        for(int j=0;j<col;j++){
            if(map[i][j]==0){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<day<<endl;
}