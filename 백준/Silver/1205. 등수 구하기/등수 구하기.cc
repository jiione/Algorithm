#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int cnt=0;
    int n, score, p;
    cin>>n>>score>>p;

    int eq=0;
    for(int i=0; i<n; ++i){
        int tmp;
        cin>>tmp;
        if(tmp == score && eq==0) eq = i+1;
        if(tmp>=score) cnt++;
        
    }

    if(cnt<p){
        if(eq!=0) cout<<eq<<'\n';
        else cout<<cnt+1<<'\n';
    }
    else cout<<-1<<'\n';

}