#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main(){
    map<int,int> mx,my;
    for(int i=0;i<3;i++){
        int x,y;
        cin>>x>>y;
        mx[x]++;
        my[y]++;
    }
    for(auto it : mx){
        if(it.second == 1) cout<<it.first<<" ";
    }
    for(auto it:  my){
        if(it.second == 1) cout<<it.first;
    }
}