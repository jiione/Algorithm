#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare (pair<int,string> p1, pair<int, string>p2 ){
    return p2.first>p1.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,string> > v;
    for(int i=0;i<N;i++){
        int tmp1;
        string tmp2;
        cin>> tmp1>>tmp2;
        v.push_back(make_pair(tmp1,tmp2));
    }
    
    stable_sort(v.begin(),v.end(),compare);
    for(auto t : v){
        cout<<t.first<<" "<<t.second<<'\n';
    }
    
}