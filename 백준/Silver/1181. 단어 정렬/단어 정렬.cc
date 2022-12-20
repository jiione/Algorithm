#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string s1, string s2){
    if(s1.length()==s2.length()){
        return s2.compare(s1)>0;
    }
    return s2.length()>s1.length();
}
int main(){
    int N;
    cin>>N;
    vector<string> v;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end(),compare);
    string prev="";
    for(auto it : v){
        if(prev.compare(it)==0) continue;
        cout<<it<<'\n';
        prev=it;
    }
    
}