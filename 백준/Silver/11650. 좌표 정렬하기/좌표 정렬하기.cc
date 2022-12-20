#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    int N;
    cin>>N;
    vector<pair<int,int> > v;
    for(int i=0;i<N;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        v.push_back(make_pair(tmp1,tmp2));
    }
    
    sort(v.begin(),v.end(),compare);
    for(auto it = v.begin();it != v.end();it++){
        cout<<it->first<<" "<<it->second<<'\n';
    }
}