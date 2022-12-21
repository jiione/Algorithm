#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    vector<int>v,v2;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v2.push_back(tmp);
    }
    sort(v.begin(),v.end());
    
    for(auto it:v2){
        cout<<upper_bound(v.begin(),v.end(),it)-lower_bound(v.begin(),v.end(),it)<<" ";
    }
}