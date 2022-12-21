#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;

        v.push_back(tmp);
    }
    vector<int> v2(v);
    sort(v2.begin(),v2.end());

    v2.erase(unique(v2.begin(),v2.end()),v2.end());

    for(int i=0;i<N;i++){
        auto it = lower_bound(v2.begin(),v2.end(),v[i]);
        cout<< it-v2.begin()<<" ";
    }

}