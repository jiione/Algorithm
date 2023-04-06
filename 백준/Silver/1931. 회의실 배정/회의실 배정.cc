#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int,int> > arr;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int cnt=0;

    cin>>N;
    int begin, end;
    for(int i=0;i<N;i++){
        cin>>begin>>end;
        arr.push_back(make_pair(end,begin));
    }
    sort(arr.begin(),arr.end());

    int time =0;

    for(int i=0;i<N;i++){
        if(time<=arr[i].second){
            cnt++;
            time=arr[i].first;
        }
    }
    cout<<cnt;
    return 0;
}
