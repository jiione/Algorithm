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
    vector<string> v;
    vector<string> result;
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<M;i++){
        cin>>tmp;
        if(binary_search(v.begin(),v.end(),tmp)){
            result.push_back(tmp);
        }
        
    }
    
    cout<<result.size()<<'\n';
    sort(result.begin(),result.end());
    for(auto it:result){
        cout<<it<<'\n';
    }
    
}