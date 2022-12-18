#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N, k;
    cin>>N>>k;
    vector<int> v;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        v.push_back(num);       
    }
    
    sort(v.rbegin(),v.rend());
    cout<<v[k-1];
}