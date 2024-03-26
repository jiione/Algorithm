#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;

    cin>>n;

    vector<pair<int,int>> v;
    vector<int> result(n);

    for(int i=0; i<n; ++i){
        int w,h;
        cin>>w>>h;

        v.push_back({w,h});
    }

    for(int i=0; i<n; ++i){
        int cw = v[i].first;
        int ch = v[i].second;
        int res = 1;
        for(int j=0; j<n; ++j){
            int nw = v[j].first;
            int nh = v[j].second;

            if(nw>cw && nh>ch) res++;
        }

        result[i] = res;
    }

    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;
}