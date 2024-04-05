#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin>>n;
    vector<string> ss(n);
    for(int i=0; i<n; ++i){
        cin>>ss[i];
    }

    int x=-1,y=-1;
    for(int i=0; i<n;++i){
        for(int j=0; j<ss[i].length();++j){
            if(ss[i][j] == '*'){
                x=j;
                y=i+1;
                cout<<y+1<<" "<<x+1<<'\n';
                break;
            }
        }
        if(x!=-1 || y!=-1) break;
    }

    int cnt=0;
    for(int i=0; i<n; ++i){
        if(i==x){
            cout<<cnt<<" ";
            cnt=0;
        }
        else if(ss[y][i]=='*') cnt++;
    }

    cout<<cnt<<" ";
    cnt=0;
    int ty=0;
    for(int i=y+1; i<n; ++i){
        if(ss[i][x]=='*') cnt++;
        else{
            ty=i;
            cout<<cnt<<" ";
            break;
        }
    }

    cnt=0;
    for(int i=ty; i<n;++i){
        if(ss[i][x-1] == '*') cnt++;
        else{
            break;
        }
    }
    cout<<cnt<<" ";
    cnt=0;
    for(int i=ty; i<n;++i){
        if(ss[i][x+1] == '*') cnt++;
        else{
            break;
        }
    }
    cout<<cnt<<" ";
    cout<<'\n';


}