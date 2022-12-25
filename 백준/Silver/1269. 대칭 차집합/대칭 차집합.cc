#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
int main(){
    int N,M;
    map<int,int> m;
    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        m[tmp]++;
    }
    for(int i=0;i<M;i++){
        cin>>tmp;
        if(m.find(tmp)!=m.end()) m.erase(tmp);
        else m[tmp]++;
    }
    
    cout<<m.size()<<'\n';
}