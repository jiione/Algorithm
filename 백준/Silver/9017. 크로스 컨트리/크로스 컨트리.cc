#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;
    for(int tc=0; tc<T; ++tc){
        int n;
        cin>>n;

        vector<pair<int,int>> score(n+1);
        for(int i=1; i<=n;++i){
            score[i].second=i;
        }

        vector<int> cntArr(n+1,0);
        vector<int> board(n+1);

        int fiveRank=1;

        for(int i=1; i<=n; ++i){
            cin>>board[i];
            cntArr[board[i]]++;
            if(cntArr[board[i]]==5) cntArr[board[i]]+=10*(fiveRank++);
        }
        int rankCnt=1;
        vector<int> fourCnt(n+1);
        for(int i=1; i<=n; ++i){
            if(cntArr[board[i]]%10==6){
                fourCnt[board[i]]++;
                if(fourCnt[board[i]] <= 4) score[board[i]].first+=rankCnt;
                rankCnt++;
            } 
        }

        sort(score.begin()+1,score.end());
        int min = 8000;
        int idx = 0;
        for(int i=1;i<=n;++i){
            if(score[i].first == 0) continue;
            else{
                min = score[i].first;
                idx=i;
                break;
            }
        }

        for(int i=idx+1; i<=n; ++i){
            if(score[i].first == score[idx].first){
                if(cntArr[score[i].second]/10 < cntArr[score[idx].second]/10){
                    idx = i;
                }
            }
            else break;
        }

        cout<<score[idx].second<<'\n';
    }
}