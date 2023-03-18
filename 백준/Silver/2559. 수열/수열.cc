#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> v;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    vector<int> v2;

    int sum=0;
    for(int i=0;i<M;i++){
        sum+=v[i];
    }
    v2.push_back(sum);

    for(int i=M;i<N;i++){
        int tmp=v2.back();
        tmp=tmp+v[i]-v[i-M];
        v2.push_back(tmp);
    }

    cout<<*max_element(v2.begin(),v2.end());
    return 0;
}
