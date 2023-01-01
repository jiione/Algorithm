#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int> > board(9,vector<int>(9,0));
vector<pair<int,int> > v;
bool checkEnd =false;
void dfs(int cnt){

    if(checkEnd ==true) return;
    if(cnt==v.size()) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<'\n';
        }
        checkEnd = true;
        return;
    }
    vector<bool> check(10,false);
    int n = v[cnt].first;
    int m = v[cnt].second;
    for(int i=0;i<9;i++){
        check[board[n][i]] =true;
        check[board[i][m]] = true;
    }
    int a=n/3;
    int b=m/3;
    a*=3;
    b*=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            check[board[a+i][b+j]] = true;
        }
    }
    for(int i=1;i<10;i++){
        if(check[i]==false){
            board[n][m]=i;
            dfs(cnt+1);
            board[n][m]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int temp;
            cin>>temp;
            board[i][j]=temp;
            if(temp==0) v.push_back(make_pair(i,j));
        }
    }
    
    dfs(0);
}