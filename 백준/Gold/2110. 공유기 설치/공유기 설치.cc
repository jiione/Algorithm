#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define endl '\n'

int N,C;
int dist = 0;
void binarySearch(vector<int> houses){
    int start = 1;
    int end = houses.back()-houses.front();

    while(end>=start){
        int mid =(start + end)/2;
        int cnt = 1;
        int cur = houses.front();
        for(int i=1; i<N; ++i){
            if(houses[i]-cur >= mid){
                cnt++;
                cur = houses[i];
            }
            if(cnt>C) break;
        }

        if(cnt<C){
            end = mid -1;
        }
        else if(cnt>=C){
            start = mid+1;
            dist = max(mid,dist);
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>C;

    vector<int> houses(N,0);

    for(int i=0; i<N; ++i){
        cin>>houses[i];
    }

    sort(houses.begin(), houses.end());

    binarySearch(houses);

    cout<<dist<<endl;

    return 0;
}