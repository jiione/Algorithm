#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    for(int i=0;i<5;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    int sum=0;
    for(auto it=v.begin();it!=v.end();it++){
        sum+=*it;
    }
    cout<<sum/(double)5<<endl<<v[2]<<endl;
}