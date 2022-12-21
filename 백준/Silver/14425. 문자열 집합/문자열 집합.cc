#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    string tmp;
    
    vector<string> v1,v2;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v1.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        cin>>tmp;
        v2.push_back(tmp);
    }
    
    sort(v1.begin(),v1.end());
    
    int i=0;
    for(auto it:v2){
        if(binary_search(v1.begin(),v1.end(),it)) i++;
    }
    cout<<i;
}