#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int MAX_TEAM_NUM = 500;

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  int team_num, changed_num, a,b;

  while(test_num--){
    int past_idx2rank[MAX_TEAM_NUM+1], past_rank2idx[MAX_TEAM_NUM+1];
    bool adj[MAX_TEAM_NUM+1][MAX_TEAM_NUM+1];
    
    memset(adj, false, sizeof(adj));
    
    cin>>team_num;
    vector<int> indegree(team_num+1,0);
    
    int team_idx;
    for(int rank=1; rank<=team_num; ++rank){
      cin>>team_idx;
      past_idx2rank[team_idx] = rank;
      past_rank2idx[rank] = team_idx;
    }

    for(int i=1; i<team_num ; ++i){
      for(int j=i+1; j<=team_num ; ++j){
        adj[past_rank2idx[i]][past_rank2idx[j]] = true;
        indegree[past_rank2idx[j]]++;
      }
    }

    cin>>changed_num;
    for(int i=0; i<changed_num ; ++i){
      cin>>a>>b;
      if(past_idx2rank[a] < past_idx2rank[b]){//저번엔 a가 더 높은 경우, 이번에는 b가 더 높은 순위임을 의미
        adj[b][a] = true;
        adj[a][b] = false;
        indegree[a]++;
        indegree[b]--;
      }else{
        adj[a][b] = true;
        adj[b][a] = false;
        indegree[b]++;
        indegree[a]--;
      }
    }

    queue<int> que;
    for(int i=1; i<=team_num ; ++i){
      if(indegree[i] == 0)
        que.push(i);
    }

    vector<int> new_ranking;
    bool is_possible = true, is_single_answer = true;
    for(int i=0; i<team_num ; ++i){
      if(que.empty()){
        is_possible = false;
        break;
      }
      team_idx = que.front();
      que.pop();

      if(que.size() >0){
        is_single_answer = false;
      }else{
        new_ranking.push_back(team_idx);
      }

      for(int j=1; j<=MAX_TEAM_NUM ; ++j){
        if(adj[team_idx][j])
          if(--indegree[j] == 0)
            que.push(j);
      }
    }

    if(!is_possible)
      cout<<"IMPOSSIBLE";
    else if(!is_single_answer)
      cout<<"?";
    else
      for(int i=0; i<team_num ; ++i)
        cout<<new_ranking[i]<<' ';
    cout<<'\n';
  }

  return 0;
}