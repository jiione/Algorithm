#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> v;
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
    for(int i=1;i<N;i++){
        cin>>tmp;
        tmp+=v.back();
        v.push_back(tmp);
    }

    int begin, end;
    for(int i=0;i<M;i++){
        cin>>begin>>end;
        cout<<v[end-1]-v[begin-2]<<'\n';
    }

    return 0;
}
