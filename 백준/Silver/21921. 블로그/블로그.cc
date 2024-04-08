#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,x;

    cin>>n>>x;

    vector<int> calender(n+1);
    vector<int> board(n+1);

    for(int i=1; i<=n;++i){
        cin>>board[i];
    }
    int left = 1;
    int right = x;
    int sum=0;
    for(int i=1;i<=x;++i){
        sum+=board[i];
    }
    int max = sum;
    int cnt=1;

    while(right<n){
        sum+=board[++right];
        sum-=board[left++];
        if(max<sum){
            max=sum;
            cnt=1;
        }
        else if(max==sum){
            cnt++;
        }
    }

    if(max==0) cout<<"SAD\n";
    else{
        cout<<max<<'\n'<<cnt<<'\n';
    }

    
}