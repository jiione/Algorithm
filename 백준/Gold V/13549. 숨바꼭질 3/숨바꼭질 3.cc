#include<iostream>
#include<vector>
#include<queue>

#define MAX 100000+1

using namespace std;

vector<bool> visited(MAX, false);  
int N,K;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second > p2.second;
    };
};

void input(){
    cin>>N>>K;
}

void solution(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({N,0});
    

    while(!pq.empty()){
        int cur = pq.top().first;
        int sec = pq.top().second;
        pq.pop();

        visited[cur] = true;

        if(cur == K){
            cout<<sec<<endl;
            return;
        }
        if(cur*2 < MAX && cur*2 <= K*2 && !visited[cur*2]){
            pq.push({cur*2,sec});
        }
        if(cur + 1 < MAX && !visited[cur+1]){
            pq.push({cur+1,sec+1});
        }
        if(cur - 1 >= 0 && !visited[cur-1]){
            pq.push({cur-1,sec+1});
        }
    }
}


int main(){
    input();
    solution();

    return 0;
}