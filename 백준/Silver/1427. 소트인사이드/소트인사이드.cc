#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    int temp;
    vector<int> v;
    for(int i=N;i!=0;i=i/10){
        temp=i%10;
        v.push_back(temp);
    }
    sort(v.rbegin(),v.rend());
    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it;
    }
}